// Copyright (c) 2025 Rafael Valoto. All Rights Reserved.
// Project: GamepadCore
// Description: Cross-platform library for DualSense and generic gamepad input support.
// Targets: Windows, Linux, macOS.
#pragma once
#include "GCore/Templates/TGenericHardwareInfo.h"
#include "GCore/Types/Structs/Context/DeviceContext.h"
#include "Implementations/Platforms/Linux/LinuxDeviceInfoSDL2.h"

// Sample Linux hardware policy adapter template
//
// This example satisfies the `IsHardwarePolicy` concept used by
// `GamepadCore::TGenericHardwareInfo`. Replace the bodies with calls to your
// concrete Linux implementation in
// `Source/Private/Implementations/Platforms/Commons/CommonsDeviceInfo.cpp`
// (e.g., forward to your FCommonsDeviceInfo logic that uses SDL HID).
namespace FLinuxPlatformSDL2
{
	struct FLinuxHardwarePolicy;
	using FLinuxHardware = GamepadCore::TGenericHardwareInfo<FLinuxHardwarePolicy>;

	struct FLinuxHardwarePolicy
	{
		FLinuxHardwarePolicy() = default;

		void Read(FDeviceContext* Context)
		{
			FLinuxDeviceInfoSDL2::Read(Context);
		}

		void Write(FDeviceContext* Context)
		{
			FLinuxDeviceInfoSDL2::Write(Context);
		}

		void Detect(std::vector<FDeviceContext>& Devices)
		{
			FLinuxDeviceInfoSDL2::Detect(Devices);
		}

		bool CreateHandle(FDeviceContext* Context)
		{
			return FLinuxDeviceInfoSDL2::CreateHandle(Context);
		}

		void InvalidateHandle(FDeviceContext* Context)
		{
			FLinuxDeviceInfoSDL2::InvalidateHandle(Context);
		}

		void ProcessAudioHaptic(FDeviceContext* Context)
		{
			FLinuxDeviceInfoSDL2::ProcessAudioHaptic(Context);
		}

		void InitializeAudioDevice(FDeviceContext* Context)
		{
			FLinuxDeviceInfoSDL2::InitializeAudioDevice(Context);
		}
	};
} // namespace FLinuxPlatformSDL2

