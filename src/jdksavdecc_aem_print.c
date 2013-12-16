
/*
  Copyright (c) 2013, J.D. Koftinoff Software, Ltd.
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

#include "jdksavdecc_world.h"
#include "jdksavdecc_aem_print.h"

struct jdksavdecc_uint16_name jdksavdecc_aem_print_command[]
    = {{JDKSAVDECC_AEM_COMMAND_ACQUIRE_ENTITY, "ACQUIRE_ENTITY"},
       {JDKSAVDECC_AEM_COMMAND_LOCK_ENTITY, "LOCK_ENTITY"},
       {JDKSAVDECC_AEM_COMMAND_ENTITY_AVAILABLE, "ENTITY_AVAILABLE"},
       {JDKSAVDECC_AEM_COMMAND_CONTROLLER_AVAILABLE, "CONTROLLER_AVAILABLE"},
       {JDKSAVDECC_AEM_COMMAND_READ_DESCRIPTOR, "READ_DESCRIPTOR"},
       {JDKSAVDECC_AEM_COMMAND_WRITE_DESCRIPTOR, "WRITE_DESCRIPTOR"},
       {JDKSAVDECC_AEM_COMMAND_SET_CONFIGURATION, "SET_CONFIGURATION"},
       {JDKSAVDECC_AEM_COMMAND_GET_CONFIGURATION, "GET_CONFIGURATION"},
       {JDKSAVDECC_AEM_COMMAND_SET_STREAM_FORMAT, "SET_STREAM_FORMAT"},
       {JDKSAVDECC_AEM_COMMAND_GET_STREAM_FORMAT, "GET_STREAM_FORMAT"},
       {JDKSAVDECC_AEM_COMMAND_SET_VIDEO_FORMAT, "SET_VIDEO_FORMAT"},
       {JDKSAVDECC_AEM_COMMAND_GET_VIDEO_FORMAT, "GET_VIDEO_FORMAT"},
       {JDKSAVDECC_AEM_COMMAND_SET_SENSOR_FORMAT, "SET_SENSOR_FORMAT"},
       {JDKSAVDECC_AEM_COMMAND_GET_SENSOR_FORMAT, "GET_SENSOR_FORMAT"},
       {JDKSAVDECC_AEM_COMMAND_SET_STREAM_INFO, "SET_STREAM_INFO"},
       {JDKSAVDECC_AEM_COMMAND_GET_STREAM_INFO, "GET_STREAM_INFO"},
       {JDKSAVDECC_AEM_COMMAND_SET_NAME, "SET_NAME"},
       {JDKSAVDECC_AEM_COMMAND_GET_NAME, "GET_NAME"},
       {JDKSAVDECC_AEM_COMMAND_SET_ASSOCIATION_ID, "SET_ASSOCIATION_ID"},
       {JDKSAVDECC_AEM_COMMAND_GET_ASSOCIATION_ID, "GET_ASSOCIATION_ID"},
       {JDKSAVDECC_AEM_COMMAND_SET_SAMPLING_RATE, "SET_SAMPLING_RATE"},
       {JDKSAVDECC_AEM_COMMAND_GET_SAMPLING_RATE, "GET_SAMPLING_RATE"},
       {JDKSAVDECC_AEM_COMMAND_SET_CLOCK_SOURCE, "SET_CLOCK_SOURCE"},
       {JDKSAVDECC_AEM_COMMAND_GET_CLOCK_SOURCE, "GET_CLOCK_SOURCE"},
       {JDKSAVDECC_AEM_COMMAND_SET_CONTROL, "SET_CONTROL"},
       {JDKSAVDECC_AEM_COMMAND_GET_CONTROL, "GET_CONTROL"},
       {JDKSAVDECC_AEM_COMMAND_INCREMENT_CONTROL, "INCREMENT_CONTROL"},
       {JDKSAVDECC_AEM_COMMAND_DECREMENT_CONTROL, "DECREMENT_CONTROL"},
       {JDKSAVDECC_AEM_COMMAND_SET_SIGNAL_SELECTOR, "SET_SIGNAL_SELECTOR"},
       {JDKSAVDECC_AEM_COMMAND_GET_SIGNAL_SELECTOR, "GET_SIGNAL_SELECTOR"},
       {JDKSAVDECC_AEM_COMMAND_SET_MIXER, "SET_MIXER"},
       {JDKSAVDECC_AEM_COMMAND_GET_MIXER, "GET_MIXER"},
       {JDKSAVDECC_AEM_COMMAND_SET_MATRIX, "SET_MATRIX"},
       {JDKSAVDECC_AEM_COMMAND_GET_MATRIX, "GET_MATRIX"},
       {JDKSAVDECC_AEM_COMMAND_START_STREAMING, "START_STREAMING"},
       {JDKSAVDECC_AEM_COMMAND_STOP_STREAMING, "STOP_STREAMING"},
       {JDKSAVDECC_AEM_COMMAND_REGISTER_UNSOLICITED_NOTIFICATION, "REGISTER_UNSOLICITED_NOTIFICATION"},
       {JDKSAVDECC_AEM_COMMAND_DEREGISTER_UNSOLICITED_NOTIFICATION, "DEREGISTER_UNSOLICITED_NOTIFICATION"},
       {JDKSAVDECC_AEM_COMMAND_IDENTIFY_NOTIFICATION, "IDENTIFY_NOTIFICATION"},
       {JDKSAVDECC_AEM_COMMAND_GET_AVB_INFO, "GET_AVB_INFO"},
       {JDKSAVDECC_AEM_COMMAND_GET_AS_PATH, "GET_AS_PATH"},
       {JDKSAVDECC_AEM_COMMAND_GET_COUNTERS, "GET_COUNTERS"},
       {JDKSAVDECC_AEM_COMMAND_REBOOT, "REBOOT"},
       {JDKSAVDECC_AEM_COMMAND_GET_AUDIO_MAP, "GET_AUDIO_MAP"},
       {JDKSAVDECC_AEM_COMMAND_ADD_AUDIO_MAPPINGS, "ADD_AUDIO_MAPPINGS"},
       {JDKSAVDECC_AEM_COMMAND_REMOVE_AUDIO_MAPPINGS, "REMOVE_AUDIO_MAPPINGS"},
       {JDKSAVDECC_AEM_COMMAND_GET_VIDEO_MAP, "GET_VIDEO_MAP"},
       {JDKSAVDECC_AEM_COMMAND_ADD_VIDEO_MAPPINGS, "ADD_VIDEO_MAPPINGS"},
       {JDKSAVDECC_AEM_COMMAND_REMOVE_VIDEO_MAPPINGS, "REMOVE_VIDEO_MAPPINGS"},
       {JDKSAVDECC_AEM_COMMAND_GET_SENSOR_MAP, "GET_SENSOR_MAP"},
       {JDKSAVDECC_AEM_COMMAND_ADD_SENSOR_MAPPINGS, "ADD_SENSOR_MAPPINGS"},
       {JDKSAVDECC_AEM_COMMAND_REMOVE_SENSOR_MAPPINGS, "REMOVE_SENSOR_MAPPINGS"},
       {JDKSAVDECC_AEM_COMMAND_START_OPERATION, "START_OPERATION"},
       {JDKSAVDECC_AEM_COMMAND_ABORT_OPERATION, "ABORT_OPERATION"},
       {JDKSAVDECC_AEM_COMMAND_OPERATION_STATUS, "OPERATION_STATUS"},
       {JDKSAVDECC_AEM_COMMAND_AUTH_ADD_KEY, "AUTH_ADD_KEY"},
       {JDKSAVDECC_AEM_COMMAND_AUTH_DELETE_KEY, "AUTH_DELETE_KEY"},
       {JDKSAVDECC_AEM_COMMAND_AUTH_GET_KEY_LIST, "AUTH_GET_KEY_LIST"},
       {JDKSAVDECC_AEM_COMMAND_AUTH_GET_KEY, "AUTH_GET_KEY"},
       {JDKSAVDECC_AEM_COMMAND_AUTH_ADD_KEY_TO_CHAIN, "AUTH_ADD_KEY_TO_CHAIN"},
       {JDKSAVDECC_AEM_COMMAND_AUTH_DELETE_KEY_FROM_CHAIN, "AUTH_DELETE_KEY_FROM_CHAIN"},
       {JDKSAVDECC_AEM_COMMAND_AUTH_GET_KEYCHAIN_LIST, "AUTH_GET_KEYCHAIN_LIST"},
       {JDKSAVDECC_AEM_COMMAND_AUTH_GET_IDENTITY, "AUTH_GET_IDENTITY"},
       {JDKSAVDECC_AEM_COMMAND_AUTH_ADD_TOKEN, "AUTH_ADD_TOKEN"},
       {JDKSAVDECC_AEM_COMMAND_AUTH_DELETE_TOKEN, "AUTH_DELETE_TOKEN"},
       {JDKSAVDECC_AEM_COMMAND_AUTHENTICATE, "AUTHENTICATE"},
       {JDKSAVDECC_AEM_COMMAND_DEAUTHENTICATE, "DEAUTHENTICATE"},
       {JDKSAVDECC_AEM_COMMAND_ENABLE_TRANSPORT_SECURITY, "ENABLE_TRANSPORT_SECURITY"},
       {JDKSAVDECC_AEM_COMMAND_DISABLE_TRANSPORT_SECURITY, "DISABLE_TRANSPORT_SECURITY"},
       {JDKSAVDECC_AEM_COMMAND_ENABLE_STREAM_ENCRYPTION, "ENABLE_STREAM_ENCRYPTION"},
       {JDKSAVDECC_AEM_COMMAND_DISABLE_STREAM_ENCRYPTION, "DISABLE_STREAM_ENCRYPTION"},
       {JDKSAVDECC_AEM_COMMAND_SET_MEMORY_OBJECT_LENGTH, "SET_MEMORY_OBJECT_LENGTH"},
       {JDKSAVDECC_AEM_COMMAND_GET_MEMORY_OBJECT_LENGTH, "GET_MEMORY_OBJECT_LENGTH"},
       {JDKSAVDECC_AEM_COMMAND_SET_STREAM_BACKUP, "SET_STREAM_BACKUP"},
       {JDKSAVDECC_AEM_COMMAND_GET_STREAM_BACKUP, "GET_STREAM_BACKUP"},
       {JDKSAVDECC_AEM_COMMAND_EXPANSION, "EXPANSION"}};
