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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "phy_transmitter_impl.h"

namespace gr {
  namespace phylayer {

    phy_transmitter::sptr
    phy_transmitter::make(double freq,double sample_rate,double tx_gain)
    {
      return gnuradio::get_initial_sptr
        (new phy_transmitter_impl(freq,sample_rate,tx_gain));
    }

    /*
     * The private constructor
     */
    phy_transmitter_impl::phy_transmitter_impl(double freq,double sample_rate,double tx_gain)
      : gr::block("phy_transmitter",
              gr::io_signature::make(0,0,0),
              gr::io_signature::make(0,0,0)),
              _freq(freq),_sample_rate(sample_rate),_tx_gain(tx_gain),tx(_freq,_sample_rate,_tx_gain,0.5)
    {
      message_port_register_in(pmt::mp("in"));
      
      set_msg_handler(pmt::mp("in"),boost::bind(&phy_transmitter_impl::handle_fun,this,_1));
    }

    /*
     * Our virtual destructor.
     */
    phy_transmitter_impl::~phy_transmitter_impl()
    {
    }

    void phy_transmitter_impl::handle_fun(pmt::pmt_t msg) {
      std::string str;
      str = pmt::symbol_to_string(msg);
      int len = str.length();
      std::vector<std::vector<unsigned char>> packets(1,std::vector<unsigned char>(len));
      memcpy(&packets[0][0],&str[0],len);
      fun::Rate phy_rate = fun::RATE_1_2_BPSK;
      tx.send_frame(packets[0],phy_rate);

      std::cout << "handlefun" << std::endl;

    }

   

  } /* namespace phylayer */
} /* namespace gr */

