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

#include "SamuLife.h"

SamuLife::SamuLife ( int w, int h, QWidget *parent ) : QMainWindow ( parent )
{
  setWindowTitle ( "SamuLife" );
  setFixedSize ( QSize ( 2*w*m_cw, h*m_ch ) );

  gameOfLife = new GameOfLife();
  gameOfLife->start();

  connect ( gameOfLife, SIGNAL ( cellsChanged ( bool **, bool ** ) ),
            this, SLOT ( updateCells ( bool **, bool ** ) ) );

}

void SamuLife::updateCells ( bool **lattice, bool **prediction )
{
  this->lattice = lattice;
  this->prediction = prediction;
  update();
}

void SamuLife::paintEvent ( QPaintEvent* )
{
  QPainter qpainter ( this );

  for ( int i {0}; i<gameOfLife->getH(); ++i )
    {
      for ( int j {0}; j<gameOfLife->getW(); ++j )
        {

          if ( lattice )
            {
              if ( lattice[i][j] )
                qpainter.fillRect ( j*m_cw, i*m_ch,
                                    m_cw, m_ch, Qt::black );
              else
                qpainter.fillRect ( j*m_cw, i*m_ch,
                                    m_cw, m_ch, Qt::white );
            }
          if ( prediction )
            {
              if ( prediction[i][j] )
                qpainter.fillRect ( gameOfLife->getW()*m_cw+j*m_cw, i*m_ch,
                                    m_cw, m_ch, Qt::black );
              else
                qpainter.fillRect ( gameOfLife->getW()*m_cw+j*m_cw, i*m_ch,
                                    m_cw, m_ch, Qt::white );
            }
          qpainter.setPen ( QPen ( Qt::red, 1 ) );

          qpainter.drawRect ( j*m_cw, i*m_ch,
                              m_cw, m_ch );

          qpainter.setPen ( QPen ( Qt::blue, 1 ) );
	  
          qpainter.drawRect ( gameOfLife->getW()*m_cw+j*m_cw, i*m_ch,
                              m_cw, m_ch );
        }
    }

  qpainter.end();
}

SamuLife::~SamuLife()
{
  delete gameOfLife;
}

