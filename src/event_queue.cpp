// Copyright 2020 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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

#include "rcpputils/event_queue.hpp"
#include <iostream>
#include <queue>

namespace rcpputils
{

static std::queue<Event> event_queue;

Event
rcpputils_get_next_event(void)
{

    auto m = event_queue.front();
    event_queue.pop();

    std::cout << "Pop from queue: Address of event entity: "
              << m.entity << std::endl;

    return m;
}

void
rcpputils_set_next_event(Event event)
{
    event_queue.push(event);

    std::cout << "Push to queue: Address of event entity: "
              << event.entity << std::endl;
}

bool
queue_is_empty()
{
    return event_queue.empty();
}

}  // namespace rcpputils