#include "Libraries/RTSGameplayTagLibrary.h"

#include "GameFramework/Actor.h"

#include "RTSGameplayTagsComponent.h"


bool URTSGameplayTagLibrary::HasGameplayTag(const AActor* Actor, const FGameplayTag& Tag)
{
    if (!IsValid(Actor))
    {
        return false;
    }

    URTSGameplayTagsComponent* GameplayTagsComponent = Actor->FindComponentByClass<URTSGameplayTagsComponent>();
    return IsValid(GameplayTagsComponent) ? GameplayTagsComponent->GetCurrentTags().HasTag(Tag) : false;
}

const FGameplayTag& URTSGameplayTagLibrary::Status_Permanent_CanBeAttacked()
{
    static FGameplayTag Tag = FGameplayTag::RequestGameplayTag(FName(TEXT("Status.Permanent.CanBeAttacked")));
    return Tag;
}
