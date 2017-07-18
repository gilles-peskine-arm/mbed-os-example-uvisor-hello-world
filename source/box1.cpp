#ifdef WITH_BOX_1
/*
 * Copyright (c) 2013-2016, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "uvisor-lib/uvisor-lib.h"
#include "mbed.h"

/* Add a box to make it work */
static const UvisorBoxAclItem g_other_box_acl[] = {
};
void other_box_main(const void *ignored)
{
    while(1);
    (void)ignored;
}
UVISOR_BOX_NAMESPACE(NULL);
UVISOR_BOX_HEAPSIZE(2048);
UVISOR_BOX_MAIN(other_box_main, osPriorityNormal, 1024);
UVISOR_BOX_CONFIG(other_box, g_other_box_acl, 1024, char);

#endif
