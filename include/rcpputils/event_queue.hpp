// Copyright 2020 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef RCUTILS__EVENT_QUEUE_HPP_
#define RCUTILS__EVENT_QUEUE_HPP_

namespace rcpputils
{

enum EventType {
    SUBSCRIPTION_EVENT,
    SERVICE_EVENT
};

typedef enum EventType EventType;

struct Event {
  void * entity;
  EventType type;
};

typedef struct Event Event;

Event
rcpputils_get_next_event();

void
rcpputils_set_next_event(Event event);


} // namespace rcpputils

#endif  // RCUTILS__EVENT_QUEUE_HPP_