/*
   Copyright (c) 2021 Christof Ruch. All rights reserved.

   Dual licensed: Distributed under Affero GPL license by default, an MIT license is available for purchase
*/

#pragma once

#include "KorgDW8000.h"
#include "KorgDW8000Parameter.h"

#include "ElectraOne.h"

namespace midikraft {

	class KorgDW8000ElectraOneParameter : public ElectraOneParameter {
	public:
		KorgDW8000ElectraOneParameter(ElectraOneControlType controlType, int num, KorgDW8000Parameter::Parameter parameter) 
			: ElectraOneParameter(controlType, KorgDW8000Parameter::findParameter(parameter)->name(), num), param_(parameter) {
		}

		virtual ElectraOneColor color() const override {
			return ElectraOneColor::pink;
		}

		virtual std::shared_ptr<SynthParameterDefinition> param() const override {
			return KorgDW8000Parameter::findParameter(param_);
		}

	private:
		KorgDW8000Parameter::Parameter param_;
	};

	class KorgDW8000_ElectraOne : public ElectraOnePreset {
	public:
		KorgDW8000_ElectraOne();
	};


}

