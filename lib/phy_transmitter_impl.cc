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
    phy_transmitter::make()
    {
      return gnuradio::get_initial_sptr
        (new phy_transmitter_impl());
    }

    /*
     * The private constructor
     */
    phy_transmitter_impl::phy_transmitter_impl()
      : gr::block("phy_transmitter",
              gr::io_signature::make(0,0,0),
              gr::io_signature::make(0,0,0))
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
      std::cout << "handlefun" << std::endl;
    }

   

  } /* namespace phylayer */
} /* namespace gr */

