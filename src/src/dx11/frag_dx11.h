#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
//
// Buffer Definitions:
//
// cbuffer PS_CONSTANTS
// {
//
//   float4x4 scissorMat;               // Offset:    0 Size:    64
//   float4 scissorExt;                 // Offset:   64 Size:    16
//   float4 scissorScale;               // Offset:   80 Size:    16
//   float4x4 paintMat;                 // Offset:   96 Size:    64
//   float4 extent;                     // Offset:  160 Size:    16
//   float4 radius;                     // Offset:  176 Size:    16
//   float4 feather;                    // Offset:  192 Size:    16
//   float4 innerCol;                   // Offset:  208 Size:    16
//   float4 outerCol;                   // Offset:  224 Size:    16
//   float4 strokeMult;                 // Offset:  240 Size:    16 [unused]
//   int texType;                       // Offset:  256 Size:     4
//   int type;                          // Offset:  260 Size:     4
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// g_sampler                         sampler      NA          NA    0        1
// g_texture                         texture  float4          2d    0        1
// PS_CONSTANTS                      cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Position              0   xyzw        0      POS   float
// TEXCOORD                 0   xy          1     NONE   float   xy
// TEXCOORD                 1     zw        1     NONE   float     zw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_TARGET                0   xyzw        0   TARGET   float   xyzw
//
//
// Constant buffer to DX9 shader constant mappings:
//
// Target Reg Buffer  Start Reg # of Regs        Data Conversion
// ---------- ------- --------- --------- ----------------------
// c0         cb0             0         3  ( FLT, FLT, FLT, FLT)
// c3         cb0             4         5  ( FLT, FLT, FLT, FLT)
// c8         cb0            10         5  ( FLT, FLT, FLT, FLT)
// c13        cb0            16         1  ( INT, INT, FLT, FLT)
//
//
// Sampler/Resource to DX9 shader sampler mappings:
//
// Target Sampler Source Sampler  Source Resource
// -------------- --------------- ----------------
// s0             s0              t0
//
//
// Level9 shader bytecode:
//
    ps_2_x
    def c14, 0.5, 0, -1, -2
    dcl t0
    dcl_2d s0
    mul r0.xy, t0.z, c1
    mad r0.xy, c0, t0.w, r0
    add r0.xy, r0, c2
    abs r0.xy, r0
    add r0.xy, r0, -c3
    mov r1.xzw, c14
    mad_sat r0.xy, r0, -c4, r1.x
    mul r0.x, r0.y, r0.x
    mul r0.yz, t0.z, c6.xxyw
    mad r0.yz, c5.xxyw, t0.w, r0
    add r0.yz, r0, c7.xxyw
    rcp r2.x, c8.x
    rcp r2.y, c8.y
    mul r2.xy, r0.yzzw, r2
    texld r3, t0, s0
    texld r2, r2, s0
    mul r4.xyz, r3.w, r3
    add r5, r1.zzww, c13.yxxy
    mul r5, r5, r5
    cmp r3.xyz, -r5.y, r4, r3
    cmp r3.yzw, -r5.z, r3.x, r3
    mul r3, r0.x, r3
    mul r3, r3, c11
    cmp r3, -r5.w, -c14.z, r3
    abs r0.yz, r0
    mul r1.yzw, r2.w, r2.xxyz
    cmp r2.xyz, -r5.y, r1.yzww, r2
    cmp r2.yzw, -r5.z, r2.x, r2
    mul r2, r2, c11
    mul r2, r0.x, r2
    cmp r2, -r5.x, r2, r3
    mov r3.xy, c8
    add r1.yz, r3.xxyw, -c9.x
    add r0.yz, r0, -r1
    max r1.yz, r0, c14.y
    max r1.w, r0.y, r0.z
    min r0.y, r1.w, c14.y
    dp2add r0.z, r1.yzzw, r1.yzzw, c14.y
    rsq r0.z, r0.z
    rcp r0.z, r0.z
    add r0.y, r0.z, r0.y
    add r0.y, r0.y, -c9.x
    mad r0.y, c10.x, r1.x, r0.y
    rcp r0.z, c10.x
    mul_sat r0.y, r0.z, r0.y
    mov r1, c11
    add r1, -r1, c12
    mad r1, r0.y, r1, c11
    mul r0, r0.x, r1
    mul r1.x, c13.y, c13.y
    cmp r0, -r1.x, r0, r2
    mov oC0, r0

// approximately 53 instruction slots used (2 texture, 51 arithmetic)
ps_4_0
dcl_constantbuffer cb0[17], immediateIndexed
dcl_sampler s0, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_input_ps linear v1.xy
dcl_input_ps linear v1.zw
dcl_output o0.xyzw
dcl_temps 3
mul r0.xy, v1.wwww, cb0[1].xyxx
mad r0.xy, cb0[0].xyxx, v1.zzzz, r0.xyxx
add r0.xy, r0.xyxx, cb0[2].xyxx
add r0.xy, |r0.xyxx|, -cb0[4].xyxx
mad_sat r0.xy, -r0.xyxx, cb0[5].xyxx, l(0.500000, 0.500000, 0.000000, 0.000000)
mul r0.x, r0.y, r0.x
if_z cb0[16].y
  mul r0.yz, v1.wwww, cb0[7].xxyx
  mad r0.yz, cb0[6].xxyx, v1.zzzz, r0.yyzy
  add r0.yz, r0.yyzy, cb0[8].xxyx
  add r1.xy, cb0[10].xyxx, -cb0[11].xxxx
  add r0.yz, |r0.yyzy|, -r1.xxyx
  max r0.w, r0.z, r0.y
  min r0.w, r0.w, l(0.000000)
  max r0.yz, r0.yyzy, l(0.000000, 0.000000, 0.000000, 0.000000)
  dp2 r0.y, r0.yzyy, r0.yzyy
  sqrt r0.y, r0.y
  add r0.y, r0.y, r0.w
  add r0.y, r0.y, -cb0[11].x
  mad r0.y, cb0[12].x, l(0.500000), r0.y
  div_sat r0.y, r0.y, cb0[12].x
  add r1.xyzw, -cb0[13].xyzw, cb0[14].xyzw
  mad r1.xyzw, r0.yyyy, r1.xyzw, cb0[13].xyzw
  mul o0.xyzw, r0.xxxx, r1.xyzw
else
  ieq r0.y, cb0[16].y, l(1)
  if_nz r0.y
    mul r0.yz, v1.wwww, cb0[7].xxyx
    mad r0.yz, cb0[6].xxyx, v1.zzzz, r0.yyzy
    add r0.yz, r0.yyzy, cb0[8].xxyx
    div r0.yz, r0.yyzy, cb0[10].xxyx
    sample r1.xyzw, r0.yzyy, t0.xyzw, s0
    ieq r0.yz, cb0[16].xxxx, l(0, 1, 2, 0)
    mul r2.xyz, r1.wwww, r1.xyzx
    movc r1.xyz, r0.yyyy, r2.xyzx, r1.xyzx
    movc r1.yzw, r0.zzzz, r1.xxxx, r1.yyzw
    mul r1.xyzw, r1.xyzw, cb0[13].xyzw
    mul o0.xyzw, r0.xxxx, r1.xyzw
  else
    ieq r0.y, cb0[16].y, l(2)
    if_nz r0.y
      mov o0.xyzw, l(1.000000,1.000000,1.000000,1.000000)
    else
      sample r1.xyzw, v1.xyxx, t0.xyzw, s0
      ieq r0.yz, cb0[16].xxxx, l(0, 1, 2, 0)
      mul r2.xyz, r1.wwww, r1.xyzx
      movc r1.xyz, r0.yyyy, r2.xyzx, r1.xyzx
      movc r1.yzw, r0.zzzz, r1.xxxx, r1.yyzw
      mul r0.xyzw, r0.xxxx, r1.xyzw
      mul o0.xyzw, r0.xyzw, cb0[13].xyzw
    endif
  endif
endif
ret
// Approximately 54 instruction slots used
#endif

const BYTE g_D3D11PixelShader_Main[] =
{
     68,  88,  66,  67, 234,  22,
    106, 113, 144,  71, 236, 237,
    173, 145,  69,  84, 225,  64,
     72,  41,   1,   0,   0,   0,
    124,  14,   0,   0,   6,   0,
      0,   0,  56,   0,   0,   0,
     24,   4,   0,   0, 168,  10,
      0,   0,  36,  11,   0,   0,
    216,  13,   0,   0,  72,  14,
      0,   0,  65, 111, 110,  57,
    216,   3,   0,   0, 216,   3,
      0,   0,   0,   2, 255, 255,
    128,   3,   0,   0,  88,   0,
      0,   0,   4,   0,  40,   0,
      0,   0,  88,   0,   0,   0,
     88,   0,   1,   0,  36,   0,
      0,   0,  88,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      3,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   4,   0,
      5,   0,   3,   0,   0,   0,
      0,   0,   0,   0,  10,   0,
      5,   0,   8,   0,   0,   0,
      0,   0,   0,   0,  16,   0,
      1,   0,  13,   0,   2,   2,
      0,   0,   1,   2, 255, 255,
     81,   0,   0,   5,  14,   0,
     15, 160,   0,   0,   0,  63,
      0,   0,   0,   0,   0,   0,
    128, 191,   0,   0,   0, 192,
     31,   0,   0,   2,   0,   0,
      0, 128,   0,   0,  15, 176,
     31,   0,   0,   2,   0,   0,
      0, 144,   0,   8,  15, 160,
      5,   0,   0,   3,   0,   0,
      3, 128,   0,   0, 170, 176,
      1,   0, 228, 160,   4,   0,
      0,   4,   0,   0,   3, 128,
      0,   0, 228, 160,   0,   0,
    255, 176,   0,   0, 228, 128,
      2,   0,   0,   3,   0,   0,
      3, 128,   0,   0, 228, 128,
      2,   0, 228, 160,  35,   0,
      0,   2,   0,   0,   3, 128,
      0,   0, 228, 128,   2,   0,
      0,   3,   0,   0,   3, 128,
      0,   0, 228, 128,   3,   0,
    228, 161,   1,   0,   0,   2,
      1,   0,  13, 128,  14,   0,
    228, 160,   4,   0,   0,   4,
      0,   0,  19, 128,   0,   0,
    228, 128,   4,   0, 228, 161,
      1,   0,   0, 128,   5,   0,
      0,   3,   0,   0,   1, 128,
      0,   0,  85, 128,   0,   0,
      0, 128,   5,   0,   0,   3,
      0,   0,   6, 128,   0,   0,
    170, 176,   6,   0, 208, 160,
      4,   0,   0,   4,   0,   0,
      6, 128,   5,   0, 208, 160,
      0,   0, 255, 176,   0,   0,
    228, 128,   2,   0,   0,   3,
      0,   0,   6, 128,   0,   0,
    228, 128,   7,   0, 208, 160,
      6,   0,   0,   2,   2,   0,
      1, 128,   8,   0,   0, 160,
      6,   0,   0,   2,   2,   0,
      2, 128,   8,   0,  85, 160,
      5,   0,   0,   3,   2,   0,
      3, 128,   0,   0, 233, 128,
      2,   0, 228, 128,  66,   0,
      0,   3,   3,   0,  15, 128,
      0,   0, 228, 176,   0,   8,
    228, 160,  66,   0,   0,   3,
      2,   0,  15, 128,   2,   0,
    228, 128,   0,   8, 228, 160,
      5,   0,   0,   3,   4,   0,
      7, 128,   3,   0, 255, 128,
      3,   0, 228, 128,   2,   0,
      0,   3,   5,   0,  15, 128,
      1,   0, 250, 128,  13,   0,
     65, 160,   5,   0,   0,   3,
      5,   0,  15, 128,   5,   0,
    228, 128,   5,   0, 228, 128,
     88,   0,   0,   4,   3,   0,
      7, 128,   5,   0,  85, 129,
      4,   0, 228, 128,   3,   0,
    228, 128,  88,   0,   0,   4,
      3,   0,  14, 128,   5,   0,
    170, 129,   3,   0,   0, 128,
      3,   0, 228, 128,   5,   0,
      0,   3,   3,   0,  15, 128,
      0,   0,   0, 128,   3,   0,
    228, 128,   5,   0,   0,   3,
      3,   0,  15, 128,   3,   0,
    228, 128,  11,   0, 228, 160,
     88,   0,   0,   4,   3,   0,
     15, 128,   5,   0, 255, 129,
     14,   0, 170, 161,   3,   0,
    228, 128,  35,   0,   0,   2,
      0,   0,   6, 128,   0,   0,
    228, 128,   5,   0,   0,   3,
      1,   0,  14, 128,   2,   0,
    255, 128,   2,   0, 144, 128,
     88,   0,   0,   4,   2,   0,
      7, 128,   5,   0,  85, 129,
      1,   0, 249, 128,   2,   0,
    228, 128,  88,   0,   0,   4,
      2,   0,  14, 128,   5,   0,
    170, 129,   2,   0,   0, 128,
      2,   0, 228, 128,   5,   0,
      0,   3,   2,   0,  15, 128,
      2,   0, 228, 128,  11,   0,
    228, 160,   5,   0,   0,   3,
      2,   0,  15, 128,   0,   0,
      0, 128,   2,   0, 228, 128,
     88,   0,   0,   4,   2,   0,
     15, 128,   5,   0,   0, 129,
      2,   0, 228, 128,   3,   0,
    228, 128,   1,   0,   0,   2,
      3,   0,   3, 128,   8,   0,
    228, 160,   2,   0,   0,   3,
      1,   0,   6, 128,   3,   0,
    208, 128,   9,   0,   0, 161,
      2,   0,   0,   3,   0,   0,
      6, 128,   0,   0, 228, 128,
      1,   0, 228, 129,  11,   0,
      0,   3,   1,   0,   6, 128,
      0,   0, 228, 128,  14,   0,
     85, 160,  11,   0,   0,   3,
      1,   0,   8, 128,   0,   0,
     85, 128,   0,   0, 170, 128,
     10,   0,   0,   3,   0,   0,
      2, 128,   1,   0, 255, 128,
     14,   0,  85, 160,  90,   0,
      0,   4,   0,   0,   4, 128,
      1,   0, 233, 128,   1,   0,
    233, 128,  14,   0,  85, 160,
      7,   0,   0,   2,   0,   0,
      4, 128,   0,   0, 170, 128,
      6,   0,   0,   2,   0,   0,
      4, 128,   0,   0, 170, 128,
      2,   0,   0,   3,   0,   0,
      2, 128,   0,   0, 170, 128,
      0,   0,  85, 128,   2,   0,
      0,   3,   0,   0,   2, 128,
      0,   0,  85, 128,   9,   0,
      0, 161,   4,   0,   0,   4,
      0,   0,   2, 128,  10,   0,
      0, 160,   1,   0,   0, 128,
      0,   0,  85, 128,   6,   0,
      0,   2,   0,   0,   4, 128,
     10,   0,   0, 160,   5,   0,
      0,   3,   0,   0,  18, 128,
      0,   0, 170, 128,   0,   0,
     85, 128,   1,   0,   0,   2,
      1,   0,  15, 128,  11,   0,
    228, 160,   2,   0,   0,   3,
      1,   0,  15, 128,   1,   0,
    228, 129,  12,   0, 228, 160,
      4,   0,   0,   4,   1,   0,
     15, 128,   0,   0,  85, 128,
      1,   0, 228, 128,  11,   0,
    228, 160,   5,   0,   0,   3,
      0,   0,  15, 128,   0,   0,
      0, 128,   1,   0, 228, 128,
      5,   0,   0,   3,   1,   0,
      1, 128,  13,   0,  85, 160,
     13,   0,  85, 160,  88,   0,
      0,   4,   0,   0,  15, 128,
      1,   0,   0, 129,   0,   0,
    228, 128,   2,   0, 228, 128,
      1,   0,   0,   2,   0,   8,
     15, 128,   0,   0, 228, 128,
    255, 255,   0,   0,  83,  72,
     68,  82, 136,   6,   0,   0,
     64,   0,   0,   0, 162,   1,
      0,   0,  89,   0,   0,   4,
     70, 142,  32,   0,   0,   0,
      0,   0,  17,   0,   0,   0,
     90,   0,   0,   3,   0,  96,
     16,   0,   0,   0,   0,   0,
     88,  24,   0,   4,   0, 112,
     16,   0,   0,   0,   0,   0,
     85,  85,   0,   0,  98,  16,
      0,   3,  50,  16,  16,   0,
      1,   0,   0,   0,  98,  16,
      0,   3, 194,  16,  16,   0,
      1,   0,   0,   0, 101,   0,
      0,   3, 242,  32,  16,   0,
      0,   0,   0,   0, 104,   0,
      0,   2,   3,   0,   0,   0,
     56,   0,   0,   8,  50,   0,
     16,   0,   0,   0,   0,   0,
    246,  31,  16,   0,   1,   0,
      0,   0,  70, 128,  32,   0,
      0,   0,   0,   0,   1,   0,
      0,   0,  50,   0,   0,  10,
     50,   0,  16,   0,   0,   0,
      0,   0,  70, 128,  32,   0,
      0,   0,   0,   0,   0,   0,
      0,   0, 166,  26,  16,   0,
      1,   0,   0,   0,  70,   0,
     16,   0,   0,   0,   0,   0,
      0,   0,   0,   8,  50,   0,
     16,   0,   0,   0,   0,   0,
     70,   0,  16,   0,   0,   0,
      0,   0,  70, 128,  32,   0,
      0,   0,   0,   0,   2,   0,
      0,   0,   0,   0,   0,  10,
     50,   0,  16,   0,   0,   0,
      0,   0,  70,   0,  16, 128,
    129,   0,   0,   0,   0,   0,
      0,   0,  70, 128,  32, 128,
     65,   0,   0,   0,   0,   0,
      0,   0,   4,   0,   0,   0,
     50,  32,   0,  14,  50,   0,
     16,   0,   0,   0,   0,   0,
     70,   0,  16, 128,  65,   0,
      0,   0,   0,   0,   0,   0,
     70, 128,  32,   0,   0,   0,
      0,   0,   5,   0,   0,   0,
      2,  64,   0,   0,   0,   0,
      0,  63,   0,   0,   0,  63,
      0,   0,   0,   0,   0,   0,
      0,   0,  56,   0,   0,   7,
     18,   0,  16,   0,   0,   0,
      0,   0,  26,   0,  16,   0,
      0,   0,   0,   0,  10,   0,
     16,   0,   0,   0,   0,   0,
     31,   0,   0,   4,  26, 128,
     32,   0,   0,   0,   0,   0,
     16,   0,   0,   0,  56,   0,
      0,   8,  98,   0,  16,   0,
      0,   0,   0,   0, 246,  31,
     16,   0,   1,   0,   0,   0,
      6, 129,  32,   0,   0,   0,
      0,   0,   7,   0,   0,   0,
     50,   0,   0,  10,  98,   0,
     16,   0,   0,   0,   0,   0,
      6, 129,  32,   0,   0,   0,
      0,   0,   6,   0,   0,   0,
    166,  26,  16,   0,   1,   0,
      0,   0,  86,   6,  16,   0,
      0,   0,   0,   0,   0,   0,
      0,   8,  98,   0,  16,   0,
      0,   0,   0,   0,  86,   6,
     16,   0,   0,   0,   0,   0,
      6, 129,  32,   0,   0,   0,
      0,   0,   8,   0,   0,   0,
      0,   0,   0,  10,  50,   0,
     16,   0,   1,   0,   0,   0,
     70, 128,  32,   0,   0,   0,
      0,   0,  10,   0,   0,   0,
      6, 128,  32, 128,  65,   0,
      0,   0,   0,   0,   0,   0,
     11,   0,   0,   0,   0,   0,
      0,   9,  98,   0,  16,   0,
      0,   0,   0,   0,  86,   6,
     16, 128, 129,   0,   0,   0,
      0,   0,   0,   0,   6,   1,
     16, 128,  65,   0,   0,   0,
      1,   0,   0,   0,  52,   0,
      0,   7, 130,   0,  16,   0,
      0,   0,   0,   0,  42,   0,
     16,   0,   0,   0,   0,   0,
     26,   0,  16,   0,   0,   0,
      0,   0,  51,   0,   0,   7,
    130,   0,  16,   0,   0,   0,
      0,   0,  58,   0,  16,   0,
      0,   0,   0,   0,   1,  64,
      0,   0,   0,   0,   0,   0,
     52,   0,   0,  10,  98,   0,
     16,   0,   0,   0,   0,   0,
     86,   6,  16,   0,   0,   0,
      0,   0,   2,  64,   0,   0,
      0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,  15,   0,
      0,   7,  34,   0,  16,   0,
      0,   0,   0,   0, 150,   5,
     16,   0,   0,   0,   0,   0,
    150,   5,  16,   0,   0,   0,
      0,   0,  75,   0,   0,   5,
     34,   0,  16,   0,   0,   0,
      0,   0,  26,   0,  16,   0,
      0,   0,   0,   0,   0,   0,
      0,   7,  34,   0,  16,   0,
      0,   0,   0,   0,  26,   0,
     16,   0,   0,   0,   0,   0,
     58,   0,  16,   0,   0,   0,
      0,   0,   0,   0,   0,   9,
     34,   0,  16,   0,   0,   0,
      0,   0,  26,   0,  16,   0,
      0,   0,   0,   0,  10, 128,
     32, 128,  65,   0,   0,   0,
      0,   0,   0,   0,  11,   0,
      0,   0,  50,   0,   0,  10,
     34,   0,  16,   0,   0,   0,
      0,   0,  10, 128,  32,   0,
      0,   0,   0,   0,  12,   0,
      0,   0,   1,  64,   0,   0,
      0,   0,   0,  63,  26,   0,
     16,   0,   0,   0,   0,   0,
     14,  32,   0,   8,  34,   0,
     16,   0,   0,   0,   0,   0,
     26,   0,  16,   0,   0,   0,
      0,   0,  10, 128,  32,   0,
      0,   0,   0,   0,  12,   0,
      0,   0,   0,   0,   0,  10,
    242,   0,  16,   0,   1,   0,
      0,   0,  70, 142,  32, 128,
     65,   0,   0,   0,   0,   0,
      0,   0,  13,   0,   0,   0,
     70, 142,  32,   0,   0,   0,
      0,   0,  14,   0,   0,   0,
     50,   0,   0,  10, 242,   0,
     16,   0,   1,   0,   0,   0,
     86,   5,  16,   0,   0,   0,
      0,   0,  70,  14,  16,   0,
      1,   0,   0,   0,  70, 142,
     32,   0,   0,   0,   0,   0,
     13,   0,   0,   0,  56,   0,
      0,   7, 242,  32,  16,   0,
      0,   0,   0,   0,   6,   0,
     16,   0,   0,   0,   0,   0,
     70,  14,  16,   0,   1,   0,
      0,   0,  18,   0,   0,   1,
     32,   0,   0,   8,  34,   0,
     16,   0,   0,   0,   0,   0,
     26, 128,  32,   0,   0,   0,
      0,   0,  16,   0,   0,   0,
      1,  64,   0,   0,   1,   0,
      0,   0,  31,   0,   4,   3,
     26,   0,  16,   0,   0,   0,
      0,   0,  56,   0,   0,   8,
     98,   0,  16,   0,   0,   0,
      0,   0, 246,  31,  16,   0,
      1,   0,   0,   0,   6, 129,
     32,   0,   0,   0,   0,   0,
      7,   0,   0,   0,  50,   0,
      0,  10,  98,   0,  16,   0,
      0,   0,   0,   0,   6, 129,
     32,   0,   0,   0,   0,   0,
      6,   0,   0,   0, 166,  26,
     16,   0,   1,   0,   0,   0,
     86,   6,  16,   0,   0,   0,
      0,   0,   0,   0,   0,   8,
     98,   0,  16,   0,   0,   0,
      0,   0,  86,   6,  16,   0,
      0,   0,   0,   0,   6, 129,
     32,   0,   0,   0,   0,   0,
      8,   0,   0,   0,  14,   0,
      0,   8,  98,   0,  16,   0,
      0,   0,   0,   0,  86,   6,
     16,   0,   0,   0,   0,   0,
      6, 129,  32,   0,   0,   0,
      0,   0,  10,   0,   0,   0,
     69,   0,   0,   9, 242,   0,
     16,   0,   1,   0,   0,   0,
    150,   5,  16,   0,   0,   0,
      0,   0,  70, 126,  16,   0,
      0,   0,   0,   0,   0,  96,
     16,   0,   0,   0,   0,   0,
     32,   0,   0,  11,  98,   0,
     16,   0,   0,   0,   0,   0,
      6, 128,  32,   0,   0,   0,
      0,   0,  16,   0,   0,   0,
      2,  64,   0,   0,   0,   0,
      0,   0,   1,   0,   0,   0,
      2,   0,   0,   0,   0,   0,
      0,   0,  56,   0,   0,   7,
    114,   0,  16,   0,   2,   0,
      0,   0, 246,  15,  16,   0,
      1,   0,   0,   0,  70,   2,
     16,   0,   1,   0,   0,   0,
     55,   0,   0,   9, 114,   0,
     16,   0,   1,   0,   0,   0,
     86,   5,  16,   0,   0,   0,
      0,   0,  70,   2,  16,   0,
      2,   0,   0,   0,  70,   2,
     16,   0,   1,   0,   0,   0,
     55,   0,   0,   9, 226,   0,
     16,   0,   1,   0,   0,   0,
    166,  10,  16,   0,   0,   0,
      0,   0,   6,   0,  16,   0,
      1,   0,   0,   0,  86,  14,
     16,   0,   1,   0,   0,   0,
     56,   0,   0,   8, 242,   0,
     16,   0,   1,   0,   0,   0,
     70,  14,  16,   0,   1,   0,
      0,   0,  70, 142,  32,   0,
      0,   0,   0,   0,  13,   0,
      0,   0,  56,   0,   0,   7,
    242,  32,  16,   0,   0,   0,
      0,   0,   6,   0,  16,   0,
      0,   0,   0,   0,  70,  14,
     16,   0,   1,   0,   0,   0,
     18,   0,   0,   1,  32,   0,
      0,   8,  34,   0,  16,   0,
      0,   0,   0,   0,  26, 128,
     32,   0,   0,   0,   0,   0,
     16,   0,   0,   0,   1,  64,
      0,   0,   2,   0,   0,   0,
     31,   0,   4,   3,  26,   0,
     16,   0,   0,   0,   0,   0,
     54,   0,   0,   8, 242,  32,
     16,   0,   0,   0,   0,   0,
      2,  64,   0,   0,   0,   0,
    128,  63,   0,   0, 128,  63,
      0,   0, 128,  63,   0,   0,
    128,  63,  18,   0,   0,   1,
     69,   0,   0,   9, 242,   0,
     16,   0,   1,   0,   0,   0,
     70,  16,  16,   0,   1,   0,
      0,   0,  70, 126,  16,   0,
      0,   0,   0,   0,   0,  96,
     16,   0,   0,   0,   0,   0,
     32,   0,   0,  11,  98,   0,
     16,   0,   0,   0,   0,   0,
      6, 128,  32,   0,   0,   0,
      0,   0,  16,   0,   0,   0,
      2,  64,   0,   0,   0,   0,
      0,   0,   1,   0,   0,   0,
      2,   0,   0,   0,   0,   0,
      0,   0,  56,   0,   0,   7,
    114,   0,  16,   0,   2,   0,
      0,   0, 246,  15,  16,   0,
      1,   0,   0,   0,  70,   2,
     16,   0,   1,   0,   0,   0,
     55,   0,   0,   9, 114,   0,
     16,   0,   1,   0,   0,   0,
     86,   5,  16,   0,   0,   0,
      0,   0,  70,   2,  16,   0,
      2,   0,   0,   0,  70,   2,
     16,   0,   1,   0,   0,   0,
     55,   0,   0,   9, 226,   0,
     16,   0,   1,   0,   0,   0,
    166,  10,  16,   0,   0,   0,
      0,   0,   6,   0,  16,   0,
      1,   0,   0,   0,  86,  14,
     16,   0,   1,   0,   0,   0,
     56,   0,   0,   7, 242,   0,
     16,   0,   0,   0,   0,   0,
      6,   0,  16,   0,   0,   0,
      0,   0,  70,  14,  16,   0,
      1,   0,   0,   0,  56,   0,
      0,   8, 242,  32,  16,   0,
      0,   0,   0,   0,  70,  14,
     16,   0,   0,   0,   0,   0,
     70, 142,  32,   0,   0,   0,
      0,   0,  13,   0,   0,   0,
     21,   0,   0,   1,  21,   0,
      0,   1,  21,   0,   0,   1,
     62,   0,   0,   1,  83,  84,
     65,  84, 116,   0,   0,   0,
     54,   0,   0,   0,   3,   0,
      0,   0,   0,   0,   0,   0,
      3,   0,   0,   0,  33,   0,
      0,   0,   4,   0,   0,   0,
      0,   0,   0,   0,   5,   0,
      0,   0,   2,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      0,   0,   2,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   1,   0,
      0,   0,   4,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      0,   0,  82,  68,  69,  70,
    172,   2,   0,   0,   1,   0,
      0,   0, 160,   0,   0,   0,
      3,   0,   0,   0,  28,   0,
      0,   0,   0,   4, 255, 255,
      0,   1,   0,   0, 121,   2,
      0,   0, 124,   0,   0,   0,
      3,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      0,   0,   1,   0,   0,   0,
      1,   0,   0,   0, 134,   0,
      0,   0,   2,   0,   0,   0,
      5,   0,   0,   0,   4,   0,
      0,   0, 255, 255, 255, 255,
      0,   0,   0,   0,   1,   0,
      0,   0,  13,   0,   0,   0,
    144,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      1,   0,   0,   0,   0,   0,
      0,   0, 103,  95, 115,  97,
    109, 112, 108, 101, 114,   0,
    103,  95, 116, 101, 120, 116,
    117, 114, 101,   0,  80,  83,
     95,  67,  79,  78,  83,  84,
     65,  78,  84,  83,   0, 171,
    171, 171, 144,   0,   0,   0,
     12,   0,   0,   0, 184,   0,
      0,   0,  16,   1,   0,   0,
      0,   0,   0,   0,   0,   0,
      0,   0, 216,   1,   0,   0,
      0,   0,   0,   0,  64,   0,
      0,   0,   2,   0,   0,   0,
    228,   1,   0,   0,   0,   0,
      0,   0, 244,   1,   0,   0,
     64,   0,   0,   0,  16,   0,
      0,   0,   2,   0,   0,   0,
      0,   2,   0,   0,   0,   0,
      0,   0,  16,   2,   0,   0,
     80,   0,   0,   0,  16,   0,
      0,   0,   2,   0,   0,   0,
      0,   2,   0,   0,   0,   0,
      0,   0,  29,   2,   0,   0,
     96,   0,   0,   0,  64,   0,
      0,   0,   2,   0,   0,   0,
    228,   1,   0,   0,   0,   0,
      0,   0,  38,   2,   0,   0,
    160,   0,   0,   0,  16,   0,
      0,   0,   2,   0,   0,   0,
      0,   2,   0,   0,   0,   0,
      0,   0,  45,   2,   0,   0,
    176,   0,   0,   0,  16,   0,
      0,   0,   2,   0,   0,   0,
      0,   2,   0,   0,   0,   0,
      0,   0,  52,   2,   0,   0,
    192,   0,   0,   0,  16,   0,
      0,   0,   2,   0,   0,   0,
      0,   2,   0,   0,   0,   0,
      0,   0,  60,   2,   0,   0,
    208,   0,   0,   0,  16,   0,
      0,   0,   2,   0,   0,   0,
      0,   2,   0,   0,   0,   0,
      0,   0,  69,   2,   0,   0,
    224,   0,   0,   0,  16,   0,
      0,   0,   2,   0,   0,   0,
      0,   2,   0,   0,   0,   0,
      0,   0,  78,   2,   0,   0,
    240,   0,   0,   0,  16,   0,
      0,   0,   0,   0,   0,   0,
      0,   2,   0,   0,   0,   0,
      0,   0,  89,   2,   0,   0,
      0,   1,   0,   0,   4,   0,
      0,   0,   2,   0,   0,   0,
    100,   2,   0,   0,   0,   0,
      0,   0, 116,   2,   0,   0,
      4,   1,   0,   0,   4,   0,
      0,   0,   2,   0,   0,   0,
    100,   2,   0,   0,   0,   0,
      0,   0, 115,  99, 105, 115,
    115, 111, 114,  77,  97, 116,
      0, 171,   3,   0,   3,   0,
      4,   0,   4,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
    115,  99, 105, 115, 115, 111,
    114,  69, 120, 116,   0, 171,
      1,   0,   3,   0,   1,   0,
      4,   0,   0,   0,   0,   0,
      0,   0,   0,   0, 115,  99,
    105, 115, 115, 111, 114,  83,
     99,  97, 108, 101,   0, 112,
     97, 105, 110, 116,  77,  97,
    116,   0, 101, 120, 116, 101,
    110, 116,   0, 114,  97, 100,
    105, 117, 115,   0, 102, 101,
     97, 116, 104, 101, 114,   0,
    105, 110, 110, 101, 114,  67,
    111, 108,   0, 111, 117, 116,
    101, 114,  67, 111, 108,   0,
    115, 116, 114, 111, 107, 101,
     77, 117, 108, 116,   0, 116,
    101, 120,  84, 121, 112, 101,
      0, 171, 171, 171,   0,   0,
      2,   0,   1,   0,   1,   0,
      0,   0,   0,   0,   0,   0,
      0,   0, 116, 121, 112, 101,
      0,  77, 105,  99, 114, 111,
    115, 111, 102, 116,  32,  40,
     82,  41,  32,  72,  76,  83,
     76,  32,  83, 104,  97, 100,
    101, 114,  32,  67, 111, 109,
    112, 105, 108, 101, 114,  32,
     54,  46,  51,  46,  57,  54,
     48,  48,  46,  49,  54,  51,
     56,  52,   0, 171,  73,  83,
     71,  78, 104,   0,   0,   0,
      3,   0,   0,   0,   8,   0,
      0,   0,  80,   0,   0,   0,
      0,   0,   0,   0,   1,   0,
      0,   0,   3,   0,   0,   0,
      0,   0,   0,   0,  15,   0,
      0,   0,  92,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      0,   0,   3,   0,   0,   0,
      1,   0,   0,   0,   3,   3,
      0,   0,  92,   0,   0,   0,
      1,   0,   0,   0,   0,   0,
      0,   0,   3,   0,   0,   0,
      1,   0,   0,   0,  12,  12,
      0,   0,  83,  86,  95,  80,
    111, 115, 105, 116, 105, 111,
    110,   0,  84,  69,  88,  67,
     79,  79,  82,  68,   0, 171,
    171, 171,  79,  83,  71,  78,
     44,   0,   0,   0,   1,   0,
      0,   0,   8,   0,   0,   0,
     32,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,
      3,   0,   0,   0,   0,   0,
      0,   0,  15,   0,   0,   0,
     83,  86,  95,  84,  65,  82,
     71,  69,  84,   0, 171, 171
};