#pragma once
#include "CharacterManagement/CharacterData.h"

#include "InstanceSettings.generated.h"

struct FReplicatedGroupMemberData;
class UInstanceDataAsset;

USTRUCT(BlueprintType)
struct FClientData
{
	GENERATED_BODY()

	FClientData() = default;
	FClientData(const FString& InUUID, const FString& InName)
		: UUID(InUUID), Name(InName) {}
	
	UPROPERTY(BlueprintReadWrite)
	FString UUID{};

	UPROPERTY(BlueprintReadWrite)
	FString Name{};

	UPROPERTY(BlueprintReadOnly)
	FSerializableCharacterData CharacterData{};
};

USTRUCT(BlueprintType)
struct FServerInstanceSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Instance Settings")
	UInstanceDataAsset* DataAsset{};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Instance Settings")
	int32 SessionID{};
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Instance Settings")
	TArray<FClientData> Players{};
};

USTRUCT(BlueprintType)
struct FInstanceSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Instance Settings")
	UInstanceDataAsset* DataAsset{};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Instance Settings")
	int32 SessionID{};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Instance Settings")
	TArray<FReplicatedGroupMemberData> Players{};
};
