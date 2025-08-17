# Sub-Monitor-Rotation-Toggle README(KOR/EN)
A simple console utility for dual-monitor setups that toggles the secondary (non-primary) monitor between landscape ↔ portrait.

Author : 엔진 / Engine ([@Engine999](https://github.com/Engine999))
Email : no8engine@gmail.com




서브 모니터 회전 토글 (Windows 10 / C / WinAPI) — 듀얼 모니터 전용



▣프로젝트 설명
-듀얼모니터 환경에서 서브 모니터의 화면 방향을 [가로→세로] / [세로→가로]로 전환하는 단순 콘솔 유틸 

-모니터 해상도는 가로(1920×1080) / 세로(1080×1920)에 한정됨 

-3대 이상의 다중 모니터 구상은 범위 외이며, 주 모니터가 아닌 서브 모니터만 대상으로 동작 
 
- EnumDisplayDevices, EnumDisplaySettingsExA, ChangeDisplaySettingsExA 사용



▣코드 설명
-핵심 흐름:
보조 모니터 탐색 → 보조 모니터 상태 획득 → DMDO_DEFAULT ↔ DMDO_90 토글 → 적용

▣ 한계 및 개선사항 
1. 해상도 하드코딩 제거 
2. 화면 회전 시 마우스 포인터 이동 직관성 문제 
(서브 모니터를 가로↔세로로 전환한 뒤, 마우스를 수평으로 이동하면 특정 y 구간에서만 다른 모니터로 넘어가고, 그 외 구간에서는 벽에 막힌 듯 이동이 제한됨)



▣테스트 환경 
OS: Windows 10
Compiler: MinGW-w64 (gcc)



Sub Monitor Rotation Toggle (Windows 10 / C / WinAPI) — Dual-Monitor Only



▣ Project Description

-A simple console utility for dual-monitor setups that toggles the secondary (non-primary) monitor between landscape ↔ portrait.

-Resolution is limited to 1920×1080 (landscape) and 1080×1920 (portrait).

-Out of scope for setups with three or more displays; only the secondary display is targeted.

-Uses WinAPI functions: EnumDisplayDevices, EnumDisplaySettingsExA, ChangeDisplaySettingsExA.



▣ Code Overview

Flow: Enumerate displays → Get secondary monitor state → Toggle DMDO_DEFAULT ↔ DMDO_90 → Apply.



▣ Limitations & Improvements

-Remove hard-coded resolutions.
Current code assumes 1920×1080/1080×1920; unsupported modes will cause DISP_CHANGE_BADMODE.

-Pointer traversal after rotation (intuitive cursor movement).
After rotating, cursor may only cross between monitors at certain y-ranges if their virtual desktop positions aren’t aligned.
Improve by also adjusting DM_POSITION (dmPosition.x/y) to align the secondary monitor (e.g., top-aligned to the right of the primary).



▣ Test Environment

-OS: Windows 10
-Compiler: MinGW-w64 (GCC)



Author : 엔진 / Engine ([@Engine999](https://github.com/Engine999))
Email : no8engine@gmail.com
