/* -*- c++ -*- */
/* 
 * Copyright 2019 gr-phylayer author.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_PHYLAYER_PHY_TRANSMITTER_IMPL_H
#define INCLUDED_PHYLAYER_PHY_TRANSMITTER_IMPL_H

#include <phylayer/phy_transmitter.h>

namespace gr {
  namespace phylayer {

    class phy_transmitter_impl : public phy_transmitter
    {
     private:
      // Nothing to declare in this block.

     public:
      phy_transmitter_impl();
      ~phy_transmitter_impl();

      // Where all the action really happens
      void handle_fun(pmt::pmt_t msg);
    };

  } // namespace phylayer
} // namespace gr

#endif /* INCLUDED_PHYLAYER_PHY_TRANSMITTER_IMPL_H */

