// Copyright RolyatWorks. All Rights Reserved.

#include "Core/AegisPlayerState.h"
#include "Net/UnrealNetwork.h"

AAegisPlayerState::AAegisPlayerState()
{
	bReplicates = true;
}

void AAegisPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAegisPlayerState, TeamId);
	DOREPLIFETIME(AAegisPlayerState, ActiveLoadout);
}
