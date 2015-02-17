/*
  Copyright (c) 2014, J.D. Koftinoff Software, Ltd.
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.

   3. Neither the name of J.D. Koftinoff Software, Ltd. nor the names of its
      contributors may be used to endorse or promote products derived from
      this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.
*/

#include "JDKSAvdeccMCU/World.hpp"
#include "JDKSAvdeccMCU/RawSocket.hpp"

namespace JDKSAvdeccMCU
{

RawSocket *RawSocketTracker::net[JDKSAVDECCMCU_MAX_RAWSOCKETS] = {};
uint16_t RawSocketTracker::num_rawsockets = 0;
uint16_t RawSocketTracker::last_recv_socket = 0;

bool RawSocketTracker::multiRecvFrame( Frame *frame )
{
    bool r = false;
    if ( last_recv_socket < num_rawsockets )
    {
        if ( net[last_recv_socket]->recvFrame( frame ) )
        {
            r = true;
        }
    }
    last_recv_socket = ( last_recv_socket + 1 ) % num_rawsockets;
    return r;
}

bool RawSocketTracker::multiSendFrame( Frame const &frame,
                                       uint8_t const *data1,
                                       uint16_t len1,
                                       uint8_t const *data2,
                                       uint16_t len2 )
{
    for ( uint16_t i = 0; i < num_rawsockets; ++i )
    {
        if ( ( frame.getBuf()[JDKSAVDECC_FRAME_HEADER_DA_OFFSET] & 0x01 )
             || ( memcmp( frame.getBuf() + JDKSAVDECC_FRAME_HEADER_SA_OFFSET,
                          net[i]->getMACAddress().value,
                          6 ) == 0 ) )
        {
            net[i]->sendFrame( frame, data1, len1, data2, len2 );
        }
    }
    return true;
}

bool RawSocketTracker::multiSendReplyFrame( Frame &frame,
                                            uint8_t const *data1,
                                            uint16_t len1,
                                            uint8_t const *data2,
                                            uint16_t len2 )
{
    for ( uint16_t i = 0; i < num_rawsockets; ++i )
    {
        if ( ( frame.getBuf()[JDKSAVDECC_FRAME_HEADER_SA_OFFSET] & 0x01 )
             || ( memcmp( frame.getBuf() + JDKSAVDECC_FRAME_HEADER_DA_OFFSET,
                          net[i]->getMACAddress().value,
                          6 ) == 0 ) )
        {
            net[i]->sendReplyFrame( frame, data1, len1, data2, len2 );
        }
    }
    return true;
}

jdksavdecc_timestamp_in_milliseconds
    RawSocketTracker::multiGetTimeInMilliseconds()
{
    if ( num_rawsockets > 0 )
    {
        return net[0]->getTimeInMilliseconds();
    }
    else
    {
        return ::JDKSAvdeccMCU::getTimeInMilliseconds();
    }
}
}