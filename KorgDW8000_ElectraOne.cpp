/*
   Copyright (c) 2021 Christof Ruch. All rights reserved.

   Dual licensed: Distributed under Affero GPL license by default, an MIT license is available for purchase
*/

#include "KorgDW8000_ElectraOne.h"

namespace midikraft {

	KorgDW8000_ElectraOne::KorgDW8000_ElectraOne() : ElectraOnePreset("Korg DW8000", "KnobKraft_DW8000")
	{
		std::vector<std::shared_ptr<ElectraOneParameter>> dw8000GeneralSetup = {
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 1, KorgDW8000Parameter::MG_FREQUENCY) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 2, KorgDW8000Parameter::MG_DELAY) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(BUTTON, 2, KorgDW8000Parameter::MG_WAVE_FORM) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 3, KorgDW8000Parameter::AUTO_BEND_TIME) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(BUTTON, 3, KorgDW8000Parameter::AUTO_BEND_SELECT) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 4, KorgDW8000Parameter::AUTO_BEND_INTENSITY) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(BUTTON, 4, KorgDW8000Parameter::AUTO_BEND_MODE) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 5, KorgDW8000Parameter::DELAY_FREQUENCY) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(BUTTON, 5, KorgDW8000Parameter::DELAY_INTENSITY) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 6, KorgDW8000Parameter::DELAY_FEEDBACK) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 7, KorgDW8000Parameter::DELAY_FACTOR) }, // TimeFine, not coarse
			{ std::make_shared<KorgDW8000ElectraOneParameter>(BUTTON, 7, KorgDW8000Parameter::DELAY_TIME) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 8, KorgDW8000Parameter::DELAY_EFFECT_LEVEL) },

			{ std::make_shared<KorgDW8000ElectraOneParameter>(BUTTON, 33, KorgDW8000Parameter::OSC1_WAVE_FORM) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(BUTTON, 34, KorgDW8000Parameter::OSC1_OCTAVE) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(BUTTON, 35, KorgDW8000Parameter::BEND_OSC) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(BUTTON, 36, KorgDW8000Parameter::BEND_VCF) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(BUTTON, 37, KorgDW8000Parameter::KBD_TRACK) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(BUTTON, 38, KorgDW8000Parameter::POLARITY) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(BUTTON, 40, KorgDW8000Parameter::ASSIGN_MODE) },

			{ std::make_shared<KorgDW8000ElectraOneParameter>(BUTTON, 41, KorgDW8000Parameter::OSC2_WAVE_FORM) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(BUTTON, 42, KorgDW8000Parameter::OSC2_OCTAVE) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(BUTTON, 43, KorgDW8000Parameter::INTERVAL) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(BUTTON, 44, KorgDW8000Parameter::DETUNE) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(BUTTON, 45, KorgDW8000Parameter::AFTER_TOUCH_OSC_MG) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(BUTTON, 46, KorgDW8000Parameter::AFTER_TOUCH_VCF) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(BUTTON, 47, KorgDW8000Parameter::AFTER_TOUCH_VCA) },

			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 33, KorgDW8000Parameter::CUTOFF) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 34, KorgDW8000Parameter::RESONANCE) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 35, KorgDW8000Parameter::MG_VCF) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 36, KorgDW8000Parameter::MG_OSC) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 37, KorgDW8000Parameter::OSC1_LEVEL) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 38, KorgDW8000Parameter::OSC2_LEVEL) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 39, KorgDW8000Parameter::NOISE_LEVEL) },

			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 41, KorgDW8000Parameter::VCF_ATTACK) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 42, KorgDW8000Parameter::VCF_DECAY) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 43, KorgDW8000Parameter::VCF_BREAK_POINT) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 44, KorgDW8000Parameter::VCF_SLOPE) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 45, KorgDW8000Parameter::VCF_SUSTAIN) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 46, KorgDW8000Parameter::VCF_RELEASE) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 47, KorgDW8000Parameter::VCF_VELOCITY_SENSIVITY) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 48, KorgDW8000Parameter::EG_INTENSITY) },

			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 49, KorgDW8000Parameter::VCA_ATTACK) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 50, KorgDW8000Parameter::VCA_DECAY) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 51, KorgDW8000Parameter::VCA_BREAK_POINT) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 52, KorgDW8000Parameter::VCA_SLOPE) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 53, KorgDW8000Parameter::VCA_SUSTAIN) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 54, KorgDW8000Parameter::VCA_RELEASE) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 55, KorgDW8000Parameter::VCA_VELOCITY_SENSIVITY) },
			{ std::make_shared<KorgDW8000ElectraOneParameter>(ENCODER, 56, KorgDW8000Parameter::PORTAMENTO) }

			//				{ std::make_shared<KorgDW8000InitPatchDefinition(BUTTON, 49)
		};
		addControllers(dw8000GeneralSetup);
	}

}