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

#ifndef INCLUDED_PHYLAYER_PHY_RECEIVER_IMPL_H
#define INCLUDED_PHYLAYER_PHY_RECEIVER_IMPL_H

#include <phylayer/phy_receiver.h>
#include<fun_ofdm/receiver.h>

namespace gr {
  namespace phylayer {

    class phy_receiver_impl : public phy_receiver
    {
     private:
      // Nothing to declare in this block.
      double _freq;
      double _sample_rate;
      double _rx_gain;

     public:
      phy_receiver_impl(double freq,double sample_rate,double rx_gain);
      ~phy_receiver_impl();

      // Where all the action really happens
      void handle_fun(pmt::pmt_t msg);

      void process_packets_callback(std::vector<std::vector<unsigned char> > packets);

    };

  } // namespace phylayer
} // namespace gr

#endif /* INCLUDED_PHYLAYER_PHY_RECEIVER_IMPL_H */

