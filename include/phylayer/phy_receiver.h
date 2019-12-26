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


#ifndef INCLUDED_PHYLAYER_PHY_RECEIVER_H
#define INCLUDED_PHYLAYER_PHY_RECEIVER_H

#include <phylayer/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace phylayer {

    /*!
     * \brief <+description of block+>
     * \ingroup phylayer
     *
     */
    class PHYLAYER_API phy_receiver : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<phy_receiver> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of phylayer::phy_receiver.
       *
       * To avoid accidental use of raw pointers, phylayer::phy_receiver's
       * constructor is in a private implementation
       * class. phylayer::phy_receiver::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace phylayer
} // namespace gr

#endif /* INCLUDED_PHYLAYER_PHY_RECEIVER_H */

