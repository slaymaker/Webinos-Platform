/*******************************************************************************
 * Copyright 2010 Telecom Italia SpA
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
 ******************************************************************************/

#ifndef POLICYSET_H_
#define POLICYSET_H_

#include <xmltools/tinyxml.h>
#include "core/BondiDebug.h"
#include "Policy.h"
#include "IPolicyBase.h"

#include <vector>
using namespace std;

class PolicySet : public IPolicyBase
	{
	
private:
	string 				policyCombiningAlgorithm;
//	vector<void*>		sortArray;
	vector<IPolicyBase*> sortArray;
	vector<PolicySet*>	policysets;
	vector<Policy*> 	policies;
	vector<Subject*> 	subjects;
	
	bool matchSubject(Request*);
	Effect evaluatePolicies(Request*);
//	Effect evaluatePolicySets(Request*);
	
public:
	PolicySet(TiXmlElement*);
	PolicySet(IPolicyBase*);
	virtual ~PolicySet();
	
	Effect evaluate(Request *);
	};

#endif /* POLICYSET_H_ */
