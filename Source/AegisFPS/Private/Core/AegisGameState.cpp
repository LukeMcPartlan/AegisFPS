// Copyright RolyatWorks. All Rights Reserved.

#include "Core/AegisGameState.h"
#include "Net/UnrealNetwork.h"

void AAegisGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAegisGameState, TeamScores);
}
