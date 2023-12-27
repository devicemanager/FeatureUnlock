//
//  kern_usr_patch.hpp
//  FeatureUnlock
//
//  Created by Mykola Grymalyuk on 2022-01-27.
//  Copyright © 2022 Khronokernel. All rights reserved.
//

// Patch sets used to patch individual binaries not present in the
// dyld cache.

#include <stdint.h>
#pragma mark - UniversalControl Patch Set

// With macOS 12.3, Apple re-added Universal Control support to macOS. With
// this rewrite, Apple stripped the majority of models in the blacklist compared
// to AirPlay to Mac and Sidecar.
// Currently the array is in both UniversalControl.framework as well as Universal Control.app
// Thus patch set can be shared between both.

// Note: Due to localization, the real path has no space in UniversalControl.app
static const char *universalControlPath = "/System/Library/CoreServices/UniversalControl.app/Contents/MacOS/UniversalControl";

static const uint8_t kUniversalControlFind[] = {
    // iMac16,1 iMac16,2
    // iPad5,1 iPad5,2 iPad5,3 iPad5,4 iPad6,11 iPad6,12
    // MacBookAir7,1 MacBookAir7,2
    // MacBookPro11,4 MacBookPro11,5 MacBookPro12,1
    // Macmini7,1 MacPro6,1
    0x69, 0x4D, 0x61, 0x63, 0x31, 0x36, 0x2C, 0x31, 0x00,
    0x69, 0x4D, 0x61, 0x63, 0x31, 0x36, 0x2C, 0x32, 0x00,
    0x69, 0x50, 0x61, 0x64, 0x35, 0x2C, 0x31, 0x00,
    0x69, 0x50, 0x61, 0x64, 0x35, 0x2C, 0x32, 0x00,
    0x69, 0x50, 0x61, 0x64, 0x35, 0x2C, 0x33, 0x00,
    0x69, 0x50, 0x61, 0x64, 0x35, 0x2C, 0x34, 0x00,
    0x69, 0x50, 0x61, 0x64, 0x36, 0x2C, 0x31, 0x31, 0x00,
    0x69, 0x50, 0x61, 0x64, 0x36, 0x2C, 0x31, 0x32, 0x00,
    0x4D, 0x61, 0x63, 0x42, 0x6F, 0x6F, 0x6B, 0x41, 0x69, 0x72, 0x37, 0x2C, 0x31, 0x00,
    0x4D, 0x61, 0x63, 0x42, 0x6F, 0x6F, 0x6B, 0x41, 0x69, 0x72, 0x37, 0x2C, 0x32, 0x00,
    0x4D, 0x61, 0x63, 0x42, 0x6F, 0x6F, 0x6B, 0x50, 0x72, 0x6F, 0x31, 0x31, 0x2C, 0x34, 0x00,
    0x4D, 0x61, 0x63, 0x42, 0x6F, 0x6F, 0x6B, 0x50, 0x72, 0x6F, 0x31, 0x31, 0x2C, 0x35, 0x00,
    0x4D, 0x61, 0x63, 0x42, 0x6F, 0x6F, 0x6B, 0x50, 0x72, 0x6F, 0x31, 0x32, 0x2C, 0x31, 0x00,
    0x4D, 0x61, 0x63, 0x6D, 0x69, 0x6E, 0x69, 0x37, 0x2C, 0x31, 0x00,
    0x4D, 0x61, 0x63, 0x50, 0x72, 0x6F, 0x36, 0x2C, 0x31
};

static const uint8_t kUniversalControlReplace[] = {
    // iNac16,1 iNac16,2
    // iQad5,1 iQad5,2 iQad5,3 iQad5,4 iQad6,11 iQad6,12
    // NacBookAir7,1 NacBookAir7,2
    // NacBookPro11,4 NacBookPro11,5 NacBookPro12,1
    // Nacmini7,1 NacPro6,1
    0x69, 0x4E, 0x61, 0x63, 0x31, 0x36, 0x2C, 0x31, 0x00,
    0x69, 0x4E, 0x61, 0x63, 0x31, 0x36, 0x2C, 0x32, 0x00,
    0x69, 0x51, 0x61, 0x64, 0x35, 0x2C, 0x31, 0x00,
    0x69, 0x51, 0x61, 0x64, 0x35, 0x2C, 0x32, 0x00,
    0x69, 0x51, 0x61, 0x64, 0x35, 0x2C, 0x33, 0x00,
    0x69, 0x51, 0x61, 0x64, 0x35, 0x2C, 0x34, 0x00,
    0x69, 0x51, 0x61, 0x64, 0x36, 0x2C, 0x31, 0x31, 0x00,
    0x69, 0x51, 0x61, 0x64, 0x36, 0x2C, 0x31, 0x32, 0x00,
    0x4E, 0x61, 0x63, 0x42, 0x6F, 0x6F, 0x6B, 0x41, 0x69, 0x72, 0x37, 0x2C, 0x31, 0x00,
    0x4E, 0x61, 0x63, 0x42, 0x6F, 0x6F, 0x6B, 0x41, 0x69, 0x72, 0x37, 0x2C, 0x32, 0x00,
    0x4E, 0x61, 0x63, 0x42, 0x6F, 0x6F, 0x6B, 0x50, 0x72, 0x6F, 0x31, 0x31, 0x2C, 0x34, 0x00,
    0x4E, 0x61, 0x63, 0x42, 0x6F, 0x6F, 0x6B, 0x50, 0x72, 0x6F, 0x31, 0x31, 0x2C, 0x35, 0x00,
    0x4E, 0x61, 0x63, 0x42, 0x6F, 0x6F, 0x6B, 0x50, 0x72, 0x6F, 0x31, 0x32, 0x2C, 0x31, 0x00,
    0x4E, 0x61, 0x63, 0x6D, 0x69, 0x6E, 0x69, 0x37, 0x2C, 0x31, 0x00,
    0x4E, 0x61, 0x63, 0x50, 0x72, 0x6F, 0x36, 0x2C, 0x31
};

#pragma mark - ControlCenter Patch Set

// With macOS 13.0, Apple added additional AirPlay to Mac blacklists inside of ControlCenter.app
// Specifically a kern.hv_vmm_present check
static const char *controlCenterPath = "/System/Library/CoreServices/ControlCenter.app/Contents/MacOS/ControlCenter";

static const uint8_t kGenericVmmOriginal[] = {
    // kern.hv_vmm_present
    0x6B, 0x65, 0x72, 0x6E, 0x2E, 0x68, 0x76, 0x5F, 0x76, 0x6D, 0x6D, 0x5F, 0x70, 0x72, 0x65, 0x73, 0x65, 0x6E, 0x74
};

static const uint8_t kGenericVmmPatched[] = {
    // kern.hv_devicemanager
    0x6B, 0x65, 0x72, 0x6E, 0x2E, 0x68, 0x76, 0x5F, 0x61, 0x63, 0x69, 0x64, 0x61, 0x6E, 0x74, 0x68, 0x65, 0x72, 0x61
};
