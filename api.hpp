#pragma once

#include "../omprs.hpp"

#ifdef _WIN32
#define OMPRS_API extern "C" __declspec(dllexport)
#else
#define OMPRS_API
#endif

// most of these macros are extracted from open.mp gdk with some obvious modifications
#define GET_PLAYER_CHECKED(player_output, playerid, fail_ret)            \
	IPlayer* player_output = OMPRSComponent::Get()->GetPlayer(playerid); \
	if (player_output == nullptr)                                        \
		return fail_ret;

#define GET_PLAYER_OBJECT_CHECKED(object_output, playerid, objectid, fail_ret)                                                   \
	IPlayerObject* object_output = OMPRSComponent::Get()->GetPlayerEntity<IPlayerObjectData, IPlayerObject>(playerid, objectid); \
	if (object_output == nullptr)                                                                                                \
		return fail_ret;

#define GET_PLAYER_TEXT_LABEL_CHECKED(text_label_output, playerid, textlabelid, fail_ret)                                                        \
	IPlayerTextLabel* text_label_output = OMPRSComponent::Get()->GetPlayerEntity<IPlayerTextLabelData, IPlayerTextLabel>(playerid, textlabelid); \
	if (text_label_output == nullptr)                                                                                                            \
		return fail_ret;

#define GET_ENTITY_CHECKED(entity_output, entity_type, entity_id, fail_ret)                \
	entity_type* entity_output = OMPRSComponent::Get()->GetEntity<entity_type>(entity_id); \
	if (entity_output == nullptr)                                                          \
		return fail_ret;