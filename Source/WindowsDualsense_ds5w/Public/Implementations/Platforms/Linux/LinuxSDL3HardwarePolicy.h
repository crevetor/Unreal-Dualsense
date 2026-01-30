// Copyright (c) 2025 Rafael Valoto. All Rights Reserved.
// Project: GamepadCore
// Description: Cross-platform library for DualSense and generic gamepad input support.
// Targets: Windows, Linux, macOS.
#pragma once

#include "GCore/Templates/TGenericHardwareInfo.h"
#include "GCore/Types/Structs/Context/DeviceContext.h"
#include "Implementations/Platforms/Linux/LinuxDeviceInfoSDL3.h"

// Sample Linux hardware policy adapter template
//
// This example satisfies the `IsHardwarePolicy` concept used by
// `GamepadCore::TGenericHardwareInfo`. Replace the bodies with calls to your
// concrete Linux implementation in
// `Source/Private/Implementations/Platforms/Commons/CommonsDeviceInfo.cpp`
// (e.g., forward to your FCommonsDeviceInfo logic that uses SDL HID).
namespace FLinuxPlatformSDL3
{
#if PLATFORM_LINUX && ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION > 6
	struct FLinuxHardwarePolicy;
	using FLinuxHardware = GamepadCore::TGenericHardwareInfo<FLinuxHardwarePolicy>;

	struct FLinuxHardwarePolicy
	{
		FLinuxHardwarePolicy() = default;

		void Read(FDeviceContext* Context)
		{
			FLinuxDeviceInfoSDL3::Read(Context);
		}

		void Write(FDeviceContext* Context)
		{
			FLinuxDeviceInfoSDL3::Write(Context);
		}

		void Detect(std::vector<FDeviceContext>& Devices)
		{
			FLinuxDeviceInfoSDL3::Detect(Devices);
		}

		bool CreateHandle(FDeviceContext* Context)
		{
			return FLinuxDeviceInfoSDL3::CreateHandle(Context);
		}

		void InvalidateHandle(FDeviceContext* Context)
		{
			FLinuxDeviceInfoSDL3::InvalidateHandle(Context);
		}

		void ProcessAudioHaptic(FDeviceContext* Context)
		{
			FLinuxDeviceInfoSDL3::ProcessAudioHaptic(Context);
		}

		void InitializeAudioDevice(FDeviceContext* Context)
		{
			FLinuxDeviceInfoSDL3::InitializeAudioDevice(Context);
		}
	};
#endif

} // namespace FLinuxPlatformSDL3
