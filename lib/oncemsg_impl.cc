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
#include "oncemsg_impl.h"

namespace gr {
  namespace phylayer {

    oncemsg::sptr
    oncemsg::make()
    {
      return gnuradio::get_initial_sptr
        (new oncemsg_impl());
    }

    /*
     * The private constructor
     */
    oncemsg_impl::oncemsg_impl()
      : gr::block("oncemsg",
              gr::io_signature::make(0,0,0),
              gr::io_signature::make(0,0,0)),
              flag(false)
    {
      
      message_port_register_in(pmt::mp("in"));
      message_port_register_out(pmt::mp("out"));

      set_msg_handler(pmt::mp("in"),boost::bind(&oncemsg_impl::handle_fun,this,_1));
    }

    /*
     * Our virtual destructor.
     */
    oncemsg_impl::~oncemsg_impl()
    {
    }

    void oncemsg_impl::handle_fun(pmt::pmt_t msg) {
      if(!flag) {
        message_port_pub(pmt::mp("out"),msg);
        flag = true;
      }

    }

    

  } /* namespace phylayer */
} /* namespace gr */

