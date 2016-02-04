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

  samuQl = new QL*[m_h];
  for ( int i {0}; i<m_h; ++i )
    {
      samuQl[i] = new QL [m_w];
    }

  latticeIndex = 0;
  bool ** lattice = lattices[latticeIndex];
  for ( int i {0}; i<m_h; ++i )
    for ( int j {0}; j<m_w; ++j )
      {
        lattice[i][j] = false;
      }

  glider ( lattice, 2*m_w/5, 2*m_h/5 );
  glider ( lattice, 3*m_w/5, 3*m_h/5 );
  glider ( lattice, 4*m_w/5, 4*m_h/5 );
  glider ( lattice, 4*m_w/5, 2*m_h/5 );
  glider ( lattice, 2*m_w/5, 4*m_h/5 );

}

bool ** GameOfLife::lattice()
{
  return lattices[latticeIndex];
}

void GameOfLife::run()
{
  while ( true )
    {
      QThread::msleep ( m_delay );

      if ( !paused )
        {
          ++m_time;
          development();
          learning();
          latticeIndex = ( latticeIndex+1 ) %2;
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
  //latticeIndex = ( latticeIndex+1 ) %2;
}


GameOfLife::~GameOfLife()
{
  for ( int i {0}; i<m_h; ++i )
    {
      delete[] lattices[0][i];
      delete[] lattices[1][i];
      delete[] predictions[i];
      delete[] samuQl[i];
    }

  delete[] samuQl;
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
long GameOfLife::getT() const
{
  return m_time;
}

void GameOfLife::learning()
{
  bool **lattice = lattices[latticeIndex];

  double img_input[40];

  for ( int r {0}; r<m_h; ++r )
    {
      for ( int c {0}; c<m_w; ++c )
        {

          std::stringstream ss;
          int ii {0};

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

                  //ss << lattice[s][o];

                  if ( lattice[s][o] )
                    {
                      ++ii;
                    }

                  //img_input[ii++] = lattice[s][o]?1.2:-1.2;

                } // if

          //std::string iis[] = {"egy", "ketto", "harom", "negy", "ot", "hat", "het", "nyolc"};

          /*
           std::string iis[] = {
          "11111111",
          	"22222222",
          	"33333333",
          	"44444444",
          	"55555555",
          	"66666666",
          	"77777777",
          	"88888888"};
          	*/
          char stmt_buffer[40];
          std::memset ( stmt_buffer, 0, 40 );
          //std::snprintf ( stmt_buffer, 40, "cell is %s %s are live",  lattice[r][c]?"true":"false", iis[ii].c_str());
          //std::snprintf ( stmt_buffer, 16, "%s%s",  lattice[r][c]?"tttttttt":"ffffffff", iis[ii].c_str());
          //QString q (stmt_buffer);
          //qDebug() <<q;

          /*
          for(int t=0; t<40;++t)
          img_input[t] = ((double)stmt_buffer[t]);
               */

          /*
          	       img_input[0] = lattice[r][c]?1.0:-1.0;
          	       img_input[1] = ((double)ii)/(double)10.0;

          	       ss << img_input[0];
          	       ss << img_input[1];
          */
          ss << lattice[r][c];
          ss << ii;


          std::string prg = ss.str();
          //SPOTriplet response = samuQl[r][c] ( lattice[r][c], prg, img_input );
          SPOTriplet response = samuQl[r][c] ( lattice[r][c], prg );
          predictions[r][c] = response;

        }

    }

}












