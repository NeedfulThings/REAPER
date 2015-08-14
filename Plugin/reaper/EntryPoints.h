////////////////////////////////////////////////////////////////////////////////
// 
// Copyright (c) 2014-2015 Ultraschall (http://ultraschall.fm)
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
// 
////////////////////////////////////////////////////////////////////////////////

#ifndef __ULTRASCHALL_REAPER_ENTRY_POINTS_H_INCL__
#define __ULTRASCHALL_REAPER_ENTRY_POINTS_H_INCL__

#include "Reaper.h"

namespace ultraschall { namespace reaper {

struct EntryPoints
{
   static HWND (*pfnGetMainHwnd_)();
   static void *(*EnumProjects_)(int idx, char *projfn, int projfnlen);
   
   static void (*pfnGetProjectPath_)(char* buffer, int bufferSize);
   static void *(*pfnEnumProjects_)(int offset, char *buffer, int bufferSize);

   static void (*pfn_format_timestr_pos_)(double timestamp, char *buffer, int bufferSize, int modeOverride);
   static double(*pfn_parse_timestr_)(const char* buffer);
   
   static int (*pfnEnumProjectMarkers_)(int offset, bool *pIsRegion, double *pTimestamp, double *pEndOfRegion, char **ppName, int *pMarkerRegionIndex);
   static int (*pfnAddProjectMarker2_)(void* projectHandle, bool isRegion, double timestamp, double endOfRegion, const char* pName, int markerRegionIndex, int color);
   static bool (*DeleteProjectMarker)(ReaProject* proj, int markrgnindexnumber, bool isrgn);
   static bool (*DeleteProjectMarkerByIndex)(ReaProject* proj, int markrgnidx);

   static int (*pfnGetNumTracks_)();
   static void* (*pfnGetTrack_)(void* projectHandle, int trackIndex);
   static void* (*pfnGetSetMediaTrackInfo_)(void* track, const char* parameter, char* newValue);
};

}}

#endif // #ifndef __ULTRASCHALL_REAPER_ENTRY_POINTS_H_INCL__