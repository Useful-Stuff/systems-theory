/*++

Copyright (c) Alex Ionescu.  All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED UNDER THE LESSER GNU PUBLIC LICENSE.
    PLEASE READ THE FILE "COPYING" IN THE TOP LEVEL DIRECTORY.

Module Name:

    hiber.c

Abstract:

    The TinyLoader portable loader is responsible for loading the TinyKRNL OS
    on a variety of hardware architectures, with a backend based on the ARC
    specification. It loads the SYSTEM hive, boot drivers and NLS files before
    passing control to the actual kernel.

Environment:

    32-bit Protected Mode

Revision History:

    Alex Ionescu - Started Implementation - 30-May-06

--*/
#include "precomp.h"

BOOLEAN HiberAbort;

/*++
 * @name BlHiberRestore
 *
 * The BlHiberRestore routine FILLMEIN
 *
 * @param DriveHandle
 *        FILLMEIN
 *
 * @param HiberFile
 *        FILLMEIN
 *
 * @return BOOLEAN
 *
 * @remarks Documentation for this routine needs to be completed.
 *
 *--*/
BOOLEAN
BlHiberRestore(IN ULONG DriveHandle,
               OUT PCHAR *HiberFile)
{
    ULONG HiberFileHandle;
    ARC_STATUS Status;

    //
    // Check if we should abort
    //
    if (HiberAbort) return FALSE;

    //
    // Try to open the hibernation file
    //
    Status = BlOpen(DriveHandle,
                    "\\hiberfil.sys",
                    ArcOpenReadOnly,
                    &HiberFileHandle);
    if(Status != ESUCCESS) return FALSE;

    //
    // FIXME: TODO
    //
    NtUnhandled();
    return FALSE;
}
