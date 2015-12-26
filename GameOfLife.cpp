/**
 * @brief Samu has learnt the rules of Conway's Game of Life
 *
 * @file GameOfLife.h
 * @author  Norbert Bátfai <nbatfai@gmail.com>
 * @version 0.0.1
 *
 * @section LICENSE
 *
 * Copyright (C) 2015, 2016 Norbert Bátfai, batfai.norbert@inf.unideb.hu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * Samu (Nahshon) has learnt the rules of Conway's Game of Life. This is
 * an example of the paper entitled "Samu in his prenatal development".
 */

#include "GameOfLife.h"

GameOfLife::GameOfLife ( int w, int h ) : m_w ( w ), m_h ( h )
{
  lattices = new bool**[2];
  lattices[0] = new bool*[m_h];
  for ( int i {0}; i<m_h; ++i )
    {
      lattices[0][i] = new bool [m_w];
    }
  lattices[1] = new bool*[m_h];
  for ( int i {0}; i<m_h; ++i )
    {
      lattices[1][i] = new bool [m_w];
    }

  predictions = new bool*[m_h];
  for ( int i {0}; i<m_h; ++i )
    {
      predictions[i] = new bool [m_w];
    }

  latticeIndex = 0;
  bool ** lattice = lattices[latticeIndex];
  for ( int i {0}; i<m_h; ++i )
    for ( int j {0}; j<m_w; ++j )
      {
        lattice[i][j] = false;
      }

  glider ( lattice, m_w/2, m_h/2 );

}


bool ** GameOfLife::lattice()
{
  return lattices[latticeIndex];
}

void GameOfLife::run()
{
  while ( true )
    {
      QThread::msleep ( 150 );

      if ( !paused )
        {
          development();
          learning();
          emit cellsChanged ( lattices[latticeIndex], predictions );
        }
    }

}

void GameOfLife::pause()
{
  paused = !paused;
}

int GameOfLife::numberOfNeighbors ( bool **lattice, int r, int c, bool state )
{
  int number {0};
  for ( int i {-1}; i<2; ++i )
    for ( int j {-1}; j<2; ++j )

      if ( ! ( ( i==0 ) && ( j==0 ) ) )
        {
          int o = c + j;
          if ( o < 0 )
            {
              o = m_w-1;
            }
          else if ( o >= m_w )
            {
              o = 0;
            }

          int s = r + i;
          if ( s < 0 )
            {
              s = m_h-1;
            }
          else if ( s >= m_h )
            {
              s = 0;
            }

          if ( lattice[s][o] == state )
            {
              ++number;
            }
        }

  return number;
}

void GameOfLife::development()
{

  bool **prevLattice = lattices[latticeIndex];
  bool **nextLattice = lattices[ ( latticeIndex+1 ) %2];

  for ( int i {0}; i<m_h; ++i )
    {
      for ( int j {0}; j<m_w; ++j )
        {

          int liveNeighbors = numberOfNeighbors ( prevLattice, i, j, true );

          if ( prevLattice[i][j] == true )
            {
              if ( liveNeighbors==2 || liveNeighbors==3 )
                {
                  nextLattice[i][j] = true;
                }
              else
                {
                  nextLattice[i][j] = false;
                }
            }
          else
            {
              if ( liveNeighbors==3 )
                {
                  nextLattice[i][j] = true;
                }
              else
                {
                  nextLattice[i][j] = false;
                }
            }
        }
    }
  latticeIndex = ( latticeIndex+1 ) %2;
}


GameOfLife::~GameOfLife()
{
  for ( int i {0}; i<m_h; ++i )
    {
      delete[] lattices[0][i];
      delete[] lattices[1][i];
      delete[] predictions[i];
    }

  delete[] predictions;
  delete[] lattices[0];
  delete[] lattices[1];
  delete[] lattices;

}

void GameOfLife::glider ( bool **lattice, int x, int y )
{

  lattice[y+0][x+2] = true;
  lattice[y+1][x+1] = true;
  lattice[y+2][x+1] = true;
  lattice[y+2][x+2] = true;
  lattice[y+2][x+3] = true;

}

int GameOfLife::getW() const
{
  return m_w;
}
int GameOfLife::getH() const
{
  return m_h;
}

void GameOfLife::learning()
{
  bool **lattice = lattices[latticeIndex];

  double img_input[9];

  for ( int r {0}; r<m_h; ++r )
    {
      for ( int c {0}; c<m_w; ++c )
        {

          std::stringstream ss;
          int ii {0};

          for ( int i {-1}; i<2; ++i )
            for ( int j {-1}; j<2; ++j )
              {
                int o = c + j;
                if ( o < 0 )
                  {
                    o = m_w-1;
                  }
                else if ( o >= m_w )
                  {
                    o = 0;
                  }

                int s = r + i;
                if ( s < 0 )
                  {
                    s = m_h-1;
                  }
                else if ( s >= m_h )
                  {
                    s = 0;
                  }

                ss << lattice[s][o];

                img_input[ii++] = lattice[s][o]?0.75:-0.75;

              } // if

          std::string prg = ss.str();
          SPOTriplet response = samuQl ( lattice[r][c], prg, img_input );
          predictions[r][c] = response;

        }

    }

}












