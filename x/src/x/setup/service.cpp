/* Copyright 2014-2018 Rsyn
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
// HOW-TO
// To a step, just include its .h below and add a call to
// "registerService<T>(name)" where T is the service class name and name how
// the service will be referred to.

#include <Rsyn/Session>

// Services
#include "x/model/DefaultTimingModelWithIdealClock.h"
#include "x/infra/iccad15/Infrastructure.h"
#include "x/jezz/Jezz.h"
#include "x/nfl/NFLegal.h"
#include "x/util/BlockageControl.h"
#include "x/util/NetlistExtractor.h"

// Registration
namespace Rsyn {
static Startup registerServices([]{
	Rsyn::Session session;

	session.registerService<Jezz>("rsyn.jezz");
	session.registerService<NFL::NFLegal>("rsyn.nfl");
	session.registerService<ICCAD15::DefaultTimingModelWithIdealClock>("rsyn.defaultTimingModelWithIdealClock");
	session.registerService<ICCAD15::Infrastructure>("ufrgs.ispd16.infra");
	session.registerService<ICCAD15::BlockageControl>("ufrgs.blockageControl");

	session.registerService<NetlistExtractor>("rsyn.netlistExtractor");
});
} // end namespace

