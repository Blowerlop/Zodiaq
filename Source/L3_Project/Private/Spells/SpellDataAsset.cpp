#include "Spells/SpellDataAsset.h"

#include "Spells/SpellAimer.h"
#include "Spells/SpellAimerParams.h"

FName USpellDataAsset::GetMontageSectionName() const
{
	return FName(*FString::Printf(TEXT("Combo_%d"), ComboIndex));
}

float USpellDataAsset::GetMontageSectionLength(int Index) const
{
	if (!IsValid(AnimationMontage))
	{
		UE_LOG(LogTemp, Error, TEXT("AnimationMontage is not valid in %s"), *GetName());
		return 0;
	}
	
	return AnimationMontage->GetSectionLength(Index);
}

#if WITH_EDITOR
void USpellDataAsset::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (!Aimer) return;
	
	if (const auto DefaultObject = Aimer.GetDefaultObject())
	{
		if (!DefaultObject->AimerParamsClass)
		{
			AimerParams = nullptr;
			return;
		}
		
		if (AimerParams && AimerParams->GetClass() == DefaultObject->AimerParamsClass.Get())
			return;
			
		AimerParams = NewObject<USpellAimerParams>(this, DefaultObject->AimerParamsClass);
	}
}
#endif
