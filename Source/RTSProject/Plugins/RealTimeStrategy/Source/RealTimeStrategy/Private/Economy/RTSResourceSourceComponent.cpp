#include "Economy/RTSResourceSourceComponent.h"

#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"

#include "RTSContainerComponent.h"
#include "RTSLog.h"


URTSResourceSourceComponent::URTSResourceSourceComponent(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
    : Super(ObjectInitializer)
{
	SetIsReplicated(true);

	// Set reasonable default values.
	CurrentResources = 1000.0f;
	MaximumResources = 1000.0f;
	GatheringFactor = 1.0f;
	GathererCapacity = 1;
}

void URTSResourceSourceComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(URTSResourceSourceComponent, CurrentResources);
}

void URTSResourceSourceComponent::BeginPlay()
{
    Super::BeginPlay();

	// Set container size.
	auto ContainerComponent = GetOwner()->FindComponentByClass<URTSContainerComponent>();

	if (ContainerComponent)
	{
		ContainerComponent->SetCapacity(GathererCapacity);
	}
}

float URTSResourceSourceComponent::ExtractResources(AActor* Gatherer, float ResourceAmount)
{
	// Compute actual amount gathered.
	float GatheredAmount = ResourceAmount * GatheringFactor;

	if (GatheredAmount > CurrentResources)
	{
		GatheredAmount = CurrentResources;
	}

	// Deduct resources.
	float OldResources = CurrentResources;
	CurrentResources -= GatheredAmount;
	float NewResources = CurrentResources;

	UE_LOG(LogRTS, Log, TEXT("Actor %s has gathered %f resources of type %s from %s, reducing remaining resources to %f."),
		*Gatherer->GetName(),
		GatheredAmount,
		*ResourceType->GetName(),
		*GetOwner()->GetName(),
		CurrentResources);

	// Notify listeners.
	OnResourcesChanged.Broadcast(OldResources, NewResources);

	// Check if we're depleted.
	if (CurrentResources <= 0)
	{
		UE_LOG(LogRTS, Log, TEXT("Actor %s has been depleted."), *GetOwner()->GetName());

        // Notify listeners.
        OnDepleted.Broadcast();

		// Destroy this actor.
		GetOwner()->Destroy();
	}

	return GatheredAmount;
}

bool URTSResourceSourceComponent::CanGathererEnter(AActor* Gatherer) const
{
	auto ContainerComponent = GetOwner()->FindComponentByClass<URTSContainerComponent>();
	return !ContainerComponent || ContainerComponent->GetContainedActors().Contains(Gatherer) || ContainerComponent->CanLoadActor(Gatherer);
}

TSubclassOf<URTSResourceType> URTSResourceSourceComponent::GetResourceType() const
{
    return ResourceType;
}

float URTSResourceSourceComponent::GetMaximumResources() const
{
    return MaximumResources;
}

float URTSResourceSourceComponent::GetGatheringFactor() const
{
    return GatheringFactor;
}

bool URTSResourceSourceComponent::MustGathererEnter() const
{
    return bGathererMustEnter;
}

int32 URTSResourceSourceComponent::GetGathererCapacity() const
{
    return GathererCapacity;
}

float URTSResourceSourceComponent::GetCurrentResources() const
{
    return CurrentResources;
}
