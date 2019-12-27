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
#include "phy_receiver_impl.h"

namespace gr {
  namespace phylayer {

    phy_receiver::sptr
    phy_receiver::make(double freq,double sample_rate,double rx_gain)
    {
      return gnuradio::get_initial_sptr
        (new phy_receiver_impl(freq,sample_rate,rx_gain));
    }

    /*
     * The private constructor
     */
    phy_receiver_impl::phy_receiver_impl(double freq,double sample_rate,double rx_gain)
      : gr::block("phy_receiver",
              gr::io_signature::make(0,0,0),
              gr::io_signature::make(0,0,0)),
              _freq(freq),_sample_rate(sample_rate),_rx_gain(rx_gain)          
    {
      message_port_register_in(pmt::mp("in"));
      message_port_register_out(pmt::mp("out"));

      set_msg_handler(pmt::mp("in"),boost::bind(&phy_receiver_impl::handle_fun,this,_1));
    }

    /*
     * Our virtual destructor.
     */
    phy_receiver_impl::~phy_receiver_impl()
    {
    }

    
    void phy_receiver_impl::handle_fun(pmt::pmt_t msg) {
      auto funcal = boost::bind(&phy_receiver_impl::process_packets_callback,this,_1);
      fun::receiver rx(funcal,5.72e9,5e6,30,"");
      getchar();
    }



    void phy_receiver_impl::process_packets_callback(std::vector<std::vector<unsigned char> > packets)
    {

        int rx_count = packets.size();
        for(int i = 0;i < rx_count;i++) {
          int len = packets[i].size();
          std::cout << len << std::endl; 
          std::string str(len,'x');
          memcpy(&str[0],&packets[i][0],len);
          pmt::pmt_t sd = pmt::string_to_symbol(str);
          message_port_pub(pmt::mp("out"),sd);
        }

    }

  } /* namespace phylayer */
} /* namespace gr */

