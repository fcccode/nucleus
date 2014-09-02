/**
 * (c) 2014 Nucleus project. All rights reserved.
 * Released under GPL v2 license. Read LICENSE for more details.
 */

#pragma once

#include "nucleus/common.h"
#include "nucleus/cpu/translator.h"
#include "nucleus/cpu/ppu/ppu_thread.h"
#include "nucleus/cpu/ppu/instructions.h"

class PPUInterpreter : public CellTranslator, public PPUInstructions
{
    PPUThread& thread;

public:
    PPUInterpreter(PPUThread& thr);

    // Decode and execute one instruction
    void step();

    /**
     * Auxiliary functions
     */
    inline bool isCarry(u64 a, u64 b);
    inline bool isCarry(u64 a, u64 b, u64 c);
    inline f32 CheckVSCR_NJ(const f32 v) const;
    inline bool CheckCondition(u32 bo, u32 bi);
    inline u64& GetRegBySPR(u32 spr);

    void add(u32 rd, u32 ra, u32 rb, u32 oe, bool rc);
    void addc(u32 rd, u32 ra, u32 rb, u32 oe, bool rc);
    void adde(u32 rd, u32 ra, u32 rb, u32 oe, bool rc);
    void addi(u32 rd, u32 ra, s32 simm16);
    void addic(u32 rd, u32 ra, s32 simm16);
    void addic_(u32 rd, u32 ra, s32 simm16);
    void addis(u32 rd, u32 ra, s32 simm16);
    void addme(u32 rd, u32 ra, u32 oe, bool rc);
    void addze(u32 rd, u32 ra, u32 oe, bool rc);
    void and(u32 ra, u32 rs, u32 rb, bool rc);
    void andc(u32 ra, u32 rs, u32 rb, bool rc);
    void andi_(u32 ra, u32 rs, u32 uimm16);
    void andis_(u32 ra, u32 rs, u32 uimm16);
    void b(s32 ll, u32 aa, u32 lk);
    void bc(u32 bo, u32 bi, s32 bd, u32 aa, u32 lk);
    void bcctr(u32 bo, u32 bi, u32 bh, u32 lk);
    void bclr(u32 bo, u32 bi, u32 bh, u32 lk);
    void cmp(u32 crfd, u32 l, u32 ra, u32 rb);
    void cmpi(u32 bf, u32 l, u32 ra, s32 simm16);
    void cmpl(u32 bf, u32 l, u32 ra, u32 rb);
    void cmpli(u32 bf, u32 l, u32 ra, u32 uimm16);
    void cntlzd(u32 ra, u32 rs, bool rc);
    void cntlzw(u32 ra, u32 rs, bool rc);
    void crand(u32 bt, u32 ba, u32 bb);
    void crandc(u32 bt, u32 ba, u32 bb);
    void creqv(u32 bt, u32 ba, u32 bb);
    void crnand(u32 bt, u32 ba, u32 bb);
    void crnor(u32 bt, u32 ba, u32 bb);
    void cror(u32 bt, u32 ba, u32 bb);
    void crorc(u32 bt, u32 ba, u32 bb);
    void crxor(u32 bt, u32 ba, u32 bb);
    void dcbf(u32 ra, u32 rb);
    void dcbst(u32 ra, u32 rb);
    void dcbt(u32 ra, u32 rb, u32 th);
    void dcbtst(u32 ra, u32 rb, u32 th);
    void dcbz(u32 ra, u32 rb);
    void divd(u32 rd, u32 ra, u32 rb, u32 oe, bool rc);
    void divdu(u32 rd, u32 ra, u32 rb, u32 oe, bool rc);
    void divw(u32 rd, u32 ra, u32 rb, u32 oe, bool rc);
    void divwu(u32 rd, u32 ra, u32 rb, u32 oe, bool rc);
    void dss(u32 strm, u32 a);
    void dst(u32 ra, u32 rb, u32 strm, u32 t);
    void dstst(u32 ra, u32 rb, u32 strm, u32 t);
    void eciwx(u32 rd, u32 ra, u32 rb);
    void ecowx(u32 rs, u32 ra, u32 rb);
    void eieio();
    void eqv(u32 ra, u32 rs, u32 rb, bool rc);
    void extsb(u32 ra, u32 rs, bool rc);
    void extsh(u32 ra, u32 rs, bool rc);
    void extsw(u32 ra, u32 rs, bool rc);
    void icbi(u32 ra, u32 rb);
    void isync();
    void lbz(u32 rd, u32 ra, s32 d);
    void lbzu(u32 rd, u32 ra, s32 d);
    void lbzux(u32 rd, u32 ra, u32 rb);
    void lbzx(u32 rd, u32 ra, u32 rb);
    void ld(u32 rd, u32 ra, s32 ds);
    void ldarx(u32 rd, u32 ra, u32 rb);
    void ldbrx(u32 rd, u32 ra, u32 rb);
    void ldu(u32 rd, u32 ra, s32 ds);
    void ldux(u32 rd, u32 ra, u32 rb);
    void ldx(u32 ra, u32 rs, u32 rb);
    void lha(u32 rs, u32 ra, s32 d);
    void lhau(u32 rs, u32 ra, s32 d);
    void lhaux(u32 rd, u32 ra, u32 rb);
    void lhax(u32 rd, u32 ra, u32 rb);
    void lhbrx(u32 rd, u32 ra, u32 rb);
    void lhz(u32 rd, u32 ra, s32 d);
    void lhzu(u32 rd, u32 ra, s32 d);
    void lhzux(u32 rd, u32 ra, u32 rb);
    void lhzx(u32 rd, u32 ra, u32 rb);
    void lmw(u32 rd, u32 ra, s32 d);
    void lswi(u32 rd, u32 ra, u32 nb);
    void lswx(u32 rd, u32 ra, u32 rb);
    void lwa(u32 rd, u32 ra, s32 ds);
    void lwarx(u32 rd, u32 ra, u32 rb);
    void lwaux(u32 rd, u32 ra, u32 rb);
    void lwax(u32 rd, u32 ra, u32 rb);
    void lwbrx(u32 rd, u32 ra, u32 rb);
    void lwz(u32 rd, u32 ra, s32 d);
    void lwzu(u32 rd, u32 ra, s32 d);
    void lwzux(u32 rd, u32 ra, u32 rb);
    void lwzx(u32 rd, u32 ra, u32 rb);
    void mcrf(u32 crfd, u32 crfs);
    void mcrfs(u32 bf, u32 bfa);
    void mfocrf(u32 a, u32 rd, u32 crm);
    void mfspr(u32 rd, u32 spr);
    void mftb(u32 rd, u32 spr);
    void mtfsb0(u32 bt, bool rc);
    void mtfsb1(u32 bt, bool rc);
    void mtfsfi(u32 crfd, u32 i, bool rc);
    void mtocrf(u32 l, u32 crm, u32 rs);
    void mtspr(u32 spr, u32 rs);
    void mulhd(u32 rd, u32 ra, u32 rb, bool rc);
    void mulhdu(u32 rd, u32 ra, u32 rb, bool rc);
    void mulhw(u32 rd, u32 ra, u32 rb, bool rc);
    void mulhwu(u32 rd, u32 ra, u32 rb, bool rc);
    void mulld(u32 rd, u32 ra, u32 rb, u32 oe, bool rc);
    void mulli(u32 rd, u32 ra, s32 simm16);
    void mullw(u32 rd, u32 ra, u32 rb, u32 oe, bool rc);
    void nand(u32 ra, u32 rs, u32 rb, bool rc);
    void neg(u32 rd, u32 ra, u32 oe, bool rc);
    void nop();
    void nor(u32 ra, u32 rs, u32 rb, bool rc);
    void or(u32 ra, u32 rs, u32 rb, bool rc);
    void orc(u32 rs, u32 ra, u32 rb, bool rc);
    void ori(u32 rs, u32 ra, u32 uimm16);
    void oris(u32 rs, u32 ra, u32 uimm16);
    void rldc_lr(u32 ra, u32 rs, u32 rb, u32 m_eb, bool is_r, bool rc);
    void rldic(u32 ra, u32 rs, u32 sh, u32 mb, bool rc);
    void rldicl(u32 ra, u32 rs, u32 sh, u32 mb, bool rc);
    void rldicr(u32 ra, u32 rs, u32 sh, u32 me, bool rc);
    void rldimi(u32 ra, u32 rs, u32 sh, u32 mb, bool rc);
    void rlwimi(u32 ra, u32 rs, u32 sh, u32 mb, u32 me, bool rc);
    void rlwinm(u32 ra, u32 rs, u32 sh, u32 mb, u32 me, bool rc);
    void rlwnm(u32 ra, u32 rs, u32 rb, u32 MB, u32 ME, bool rc);
    void sc(u32 sc_code);
    void sld(u32 ra, u32 rs, u32 rb, bool rc);
    void slw(u32 ra, u32 rs, u32 rb, bool rc);
    void srad(u32 ra, u32 rs, u32 rb, bool rc);
    void sradi1(u32 ra, u32 rs, u32 sh, bool rc);
    void sradi2(u32 ra, u32 rs, u32 sh, bool rc);
    void sraw(u32 ra, u32 rs, u32 rb, bool rc);
    void srawi(u32 ra, u32 rs, u32 sh, bool rc);
    void srd(u32 ra, u32 rs, u32 rb, bool rc);
    void srw(u32 ra, u32 rs, u32 rb, bool rc);
    void stb(u32 rs, u32 ra, s32 d);
    void stbu(u32 rs, u32 ra, s32 d);
    void stbux(u32 rs, u32 ra, u32 rb);
    void stbx(u32 rs, u32 ra, u32 rb);
    void std(u32 rs, u32 ra, s32 ds);
    void stdcx_(u32 rs, u32 ra, u32 rb);
    void stdu(u32 rs, u32 ra, s32 ds);
    void stdux(u32 rs, u32 ra, u32 rb);
    void stdx(u32 rs, u32 ra, u32 rb);
    void sth(u32 rs, u32 ra, s32 d);
    void sthbrx(u32 rs, u32 ra, u32 rb);
    void sthu(u32 rs, u32 ra, s32 d);
    void sthux(u32 rs, u32 ra, u32 rb);
    void sthx(u32 rs, u32 ra, u32 rb);
    void stmw(u32 rs, u32 ra, s32 d);
    void stswi(u32 rd, u32 ra, u32 nb);
    void stswx(u32 rs, u32 ra, u32 rb);
    void stvrxl(u32 sd, u32 ra, u32 rb);
    void stw(u32 rs, u32 ra, s32 d);
    void stwbrx(u32 rs, u32 ra, u32 rb);
    void stwcx_(u32 rs, u32 ra, u32 rb);
    void stwu(u32 rs, u32 ra, s32 d);
    void stwux(u32 rs, u32 ra, u32 rb);
    void stwx(u32 rs, u32 ra, u32 rb);
    void subf(u32 rd, u32 ra, u32 rb, u32 oe, bool rc);
    void subfc(u32 rd, u32 ra, u32 rb, u32 oe, bool rc);
    void subfe(u32 rd, u32 ra, u32 rb, u32 oe, bool rc);
    void subfic(u32 rd, u32 ra, s32 simm16);
    void subfme(u32 rd, u32 ra, u32 oe, bool rc);
    void subfze(u32 rd, u32 ra, u32 oe, bool rc);
    void sync(u32 l);
    void td(u32 to, u32 ra, u32 rb);
    void tdi(u32 to, u32 ra, s32 simm16);
    void tw(u32 to, u32 ra, u32 rb);
    void twi(u32 to, u32 ra, s32 simm16);
    void xor(u32 rs, u32 ra, u32 rb, bool rc);
    void xori(u32 ra, u32 rs, u32 uimm16);
    void xoris(u32 ra, u32 rs, u32 uimm16);

    // Floating-Point Unit instructions
    void lfd(u32 frd, u32 ra, s32 d);
    void lfdu(u32 frd, u32 ra, s32 d);
    void lfdux(u32 frd, u32 ra, u32 rb);
    void lfdx(u32 frd, u32 ra, u32 rb);
    void lfs(u32 frd, u32 ra, s32 d);
    void lfsu(u32 frd, u32 ra, s32 d);
    void lfsux(u32 frd, u32 ra, u32 rb);
    void lfsx(u32 frd, u32 ra, u32 rb);
    void fabs(u32 frd, u32 frb, bool rc);
    void fadd(u32 frd, u32 fra, u32 frb, bool rc);
    void fadds(u32 frd, u32 fra, u32 frb, bool rc);
    void fcfid(u32 frd, u32 frb, bool rc);
    void fcmpo(u32 crfd, u32 fra, u32 frb);
    void fcmpu(u32 crfd, u32 fra, u32 frb);
    void fctid(u32 frd, u32 frb, bool rc);
    void fctidz(u32 frd, u32 frb, bool rc);
    void fctiw(u32 frd, u32 frb, bool rc);
    void fctiwz(u32 frd, u32 frb, bool rc);
    void fdiv(u32 frd, u32 fra, u32 frb, bool rc);
    void fdivs(u32 frd, u32 fra, u32 frb, bool rc);
    void fmadd(u32 frd, u32 fra, u32 frc, u32 frb, bool rc);
    void fmadds(u32 frd, u32 fra, u32 frc, u32 frb, bool rc);
    void fmr(u32 frd, u32 frb, bool rc);
    void fmsub(u32 frd, u32 fra, u32 frc, u32 frb, bool rc);
    void fmsubs(u32 frd, u32 fra, u32 frc, u32 frb, bool rc);
    void fmul(u32 frd, u32 fra, u32 frc, bool rc);
    void fmuls(u32 frd, u32 fra, u32 frc, bool rc);
    void fnabs(u32 frd, u32 frb, bool rc);
    void fneg(u32 frd, u32 frb, bool rc);
    void fnmadd(u32 frd, u32 fra, u32 frc, u32 frb, bool rc);
    void fnmadds(u32 frd, u32 fra, u32 frc, u32 frb, bool rc);
    void fnmsub(u32 frd, u32 fra, u32 frc, u32 frb, bool rc);
    void fnmsubs(u32 frd, u32 fra, u32 frc, u32 frb, bool rc);
    void fres(u32 frd, u32 frb, bool rc);
    void frsp(u32 frd, u32 frb, bool rc);
    void frsqrte(u32 frd, u32 frb, bool rc);
    void fsel(u32 frd, u32 fra, u32 frc, u32 frb, bool rc);
    void fsqrt(u32 frd, u32 frb, bool rc);
    void fsqrts(u32 frd, u32 frb, bool rc);
    void fsub(u32 frd, u32 fra, u32 frb, bool rc);
    void fsubs(u32 frd, u32 fra, u32 frb, bool rc);
    void mffs(u32 frd, bool rc);
    void mtfsf(u32 flm, u32 frb, bool rc);
    void stfd(u32 frs, u32 ra, s32 d);
    void stfdu(u32 frs, u32 ra, s32 d);
    void stfdux(u32 frs, u32 ra, u32 rb);
    void stfdx(u32 frs, u32 ra, u32 rb);
    void stfiwx(u32 frs, u32 ra, u32 rb);
    void stfs(u32 frs, u32 ra, s32 d);
    void stfsu(u32 frs, u32 ra, s32 d);
    void stfsux(u32 frs, u32 ra, u32 rb);
    void stfsx(u32 frs, u32 ra, u32 rb);

    // Vector/SIMD instructions
    void lvebx(u32 vd, u32 ra, u32 rb);
    void lvehx(u32 vd, u32 ra, u32 rb);
    void lvewx(u32 vd, u32 ra, u32 rb);
    void lvlx(u32 vd, u32 ra, u32 rb);
    void lvlxl(u32 vd, u32 ra, u32 rb);
    void lvrx(u32 vd, u32 ra, u32 rb);
    void lvrxl(u32 vd, u32 ra, u32 rb);
    void lvsl(u32 vd, u32 ra, u32 rb);
    void lvsr(u32 vd, u32 ra, u32 rb);
    void lvx(u32 vd, u32 ra, u32 rb);
    void lvxl(u32 vd, u32 ra, u32 rb);
    void mfvscr(u32 vd);
    void mtvscr(u32 vb);
    void stvebx(u32 vs, u32 ra, u32 rb);
    void stvehx(u32 vs, u32 ra, u32 rb);
    void stvewx(u32 vs, u32 ra, u32 rb);
    void stvlx(u32 vs, u32 ra, u32 rb);
    void stvlxl(u32 vs, u32 ra, u32 rb);
    void stvrx(u32 vs, u32 ra, u32 rb);
    void stvx(u32 vs, u32 ra, u32 rb);
    void stvxl(u32 vs, u32 ra, u32 rb);
    void vaddcuw(u32 vd, u32 va, u32 vb);
    void vaddfp(u32 vd, u32 va, u32 vb);
    void vaddsbs(u32 vd, u32 va, u32 vb);
    void vaddshs(u32 vd, u32 va, u32 vb);
    void vaddsws(u32 vd, u32 va, u32 vb);
    void vaddubm(u32 vd, u32 va, u32 vb);
    void vaddubs(u32 vd, u32 va, u32 vb);
    void vadduhm(u32 vd, u32 va, u32 vb);
    void vadduhs(u32 vd, u32 va, u32 vb);
    void vadduwm(u32 vd, u32 va, u32 vb);
    void vadduws(u32 vd, u32 va, u32 vb);
    void vand(u32 vd, u32 va, u32 vb);
    void vandc(u32 vd, u32 va, u32 vb);
    void vavgsb(u32 vd, u32 va, u32 vb);
    void vavgsh(u32 vd, u32 va, u32 vb);
    void vavgsw(u32 vd, u32 va, u32 vb);
    void vavgub(u32 vd, u32 va, u32 vb);
    void vavguh(u32 vd, u32 va, u32 vb);
    void vavguw(u32 vd, u32 va, u32 vb);
    void vcfsx(u32 vd, u32 uimm5, u32 vb);
    void vcfux(u32 vd, u32 uimm5, u32 vb);
    void vcmpbfp(u32 vd, u32 va, u32 vb);
    void vcmpbfp_(u32 vd, u32 va, u32 vb);
    void vcmpeqfp(u32 vd, u32 va, u32 vb);
    void vcmpeqfp_(u32 vd, u32 va, u32 vb);
    void vcmpequb(u32 vd, u32 va, u32 vb);
    void vcmpequb_(u32 vd, u32 va, u32 vb);
    void vcmpequh(u32 vd, u32 va, u32 vb);
    void vcmpequh_(u32 vd, u32 va, u32 vb);
    void vcmpequw(u32 vd, u32 va, u32 vb);
    void vcmpequw_(u32 vd, u32 va, u32 vb);
    void vcmpgefp(u32 vd, u32 va, u32 vb);
    void vcmpgefp_(u32 vd, u32 va, u32 vb);
    void vcmpgtfp(u32 vd, u32 va, u32 vb);
    void vcmpgtfp_(u32 vd, u32 va, u32 vb);
    void vcmpgtsb(u32 vd, u32 va, u32 vb);
    void vcmpgtsb_(u32 vd, u32 va, u32 vb);
    void vcmpgtsh(u32 vd, u32 va, u32 vb);
    void vcmpgtsh_(u32 vd, u32 va, u32 vb);
    void vcmpgtsw(u32 vd, u32 va, u32 vb);
    void vcmpgtsw_(u32 vd, u32 va, u32 vb);
    void vcmpgtub(u32 vd, u32 va, u32 vb);
    void vcmpgtub_(u32 vd, u32 va, u32 vb);
    void vcmpgtuh(u32 vd, u32 va, u32 vb);
    void vcmpgtuh_(u32 vd, u32 va, u32 vb);
    void vcmpgtuw(u32 vd, u32 va, u32 vb);
    void vcmpgtuw_(u32 vd, u32 va, u32 vb);
    void vctsxs(u32 vd, u32 uimm5, u32 vb);
    void vctuxs(u32 vd, u32 uimm5, u32 vb);
    void vexptefp(u32 vd, u32 vb);
    void vlogefp(u32 vd, u32 vb);
    void vmaddfp(u32 vd, u32 va, u32 vc, u32 vb);
    void vmaxfp(u32 vd, u32 va, u32 vb);
    void vmaxsb(u32 vd, u32 va, u32 vb);
    void vmaxsh(u32 vd, u32 va, u32 vb);
    void vmaxsw(u32 vd, u32 va, u32 vb);
    void vmaxub(u32 vd, u32 va, u32 vb);
    void vmaxuh(u32 vd, u32 va, u32 vb);
    void vmaxuw(u32 vd, u32 va, u32 vb);
    void vmhaddshs(u32 vd, u32 va, u32 vb, u32 vc);
    void vmhraddshs(u32 vd, u32 va, u32 vb, u32 vc);
    void vminfp(u32 vd, u32 va, u32 vb);
    void vminsb(u32 vd, u32 va, u32 vb);
    void vminsh(u32 vd, u32 va, u32 vb);
    void vminsw(u32 vd, u32 va, u32 vb);
    void vminub(u32 vd, u32 va, u32 vb);
    void vminuh(u32 vd, u32 va, u32 vb);
    void vminuw(u32 vd, u32 va, u32 vb);
    void vmladduhm(u32 vd, u32 va, u32 vb, u32 vc);
    void vmrghb(u32 vd, u32 va, u32 vb);
    void vmrghh(u32 vd, u32 va, u32 vb);
    void vmrghw(u32 vd, u32 va, u32 vb);
    void vmrglb(u32 vd, u32 va, u32 vb);
    void vmrglh(u32 vd, u32 va, u32 vb);
    void vmrglw(u32 vd, u32 va, u32 vb);
    void vmsummbm(u32 vd, u32 va, u32 vb, u32 vc);
    void vmsumshm(u32 vd, u32 va, u32 vb, u32 vc);
    void vmsumshs(u32 vd, u32 va, u32 vb, u32 vc);
    void vmsumubm(u32 vd, u32 va, u32 vb, u32 vc);
    void vmsumuhm(u32 vd, u32 va, u32 vb, u32 vc);
    void vmsumuhs(u32 vd, u32 va, u32 vb, u32 vc);
    void vmulesb(u32 vd, u32 va, u32 vb);
    void vmulesh(u32 vd, u32 va, u32 vb);
    void vmuleub(u32 vd, u32 va, u32 vb);
    void vmuleuh(u32 vd, u32 va, u32 vb);
    void vmulosb(u32 vd, u32 va, u32 vb);
    void vmulosh(u32 vd, u32 va, u32 vb);
    void vmuloub(u32 vd, u32 va, u32 vb);
    void vmulouh(u32 vd, u32 va, u32 vb);
    void vnmsubfp(u32 vd, u32 va, u32 vc, u32 vb);
    void vnor(u32 vd, u32 va, u32 vb);
    void vor(u32 vd, u32 va, u32 vb);
    void vperm(u32 vd, u32 va, u32 vb, u32 vc);
    void vpkpx(u32 vd, u32 va, u32 vb);
    void vpkshss(u32 vd, u32 va, u32 vb);
    void vpkshus(u32 vd, u32 va, u32 vb);
    void vpkswss(u32 vd, u32 va, u32 vb);
    void vpkswus(u32 vd, u32 va, u32 vb);
    void vpkuhum(u32 vd, u32 va, u32 vb);
    void vpkuhus(u32 vd, u32 va, u32 vb);
    void vpkuwum(u32 vd, u32 va, u32 vb);
    void vpkuwus(u32 vd, u32 va, u32 vb);
    void vrefp(u32 vd, u32 vb);
    void vrfim(u32 vd, u32 vb);
    void vrfin(u32 vd, u32 vb);
    void vrfip(u32 vd, u32 vb);
    void vrfiz(u32 vd, u32 vb);
    void vrlb(u32 vd, u32 va, u32 vb);
    void vrlh(u32 vd, u32 va, u32 vb);
    void vrlw(u32 vd, u32 va, u32 vb);
    void vrsqrtefp(u32 vd, u32 vb);
    void vsel(u32 vd, u32 va, u32 vb, u32 vc);
    void vsl(u32 vd, u32 va, u32 vb);
    void vslb(u32 vd, u32 va, u32 vb);
    void vsldoi(u32 vd, u32 va, u32 vb, u32 sh);
    void vslh(u32 vd, u32 va, u32 vb);
    void vslo(u32 vd, u32 va, u32 vb);
    void vslw(u32 vd, u32 va, u32 vb);
    void vspltb(u32 vd, u32 uimm5, u32 vb);
    void vsplth(u32 vd, u32 uimm5, u32 vb);
    void vspltisb(u32 vd, s32 simm5);
    void vspltish(u32 vd, s32 simm5);
    void vspltisw(u32 vd, s32 simm5);
    void vspltw(u32 vd, u32 uimm5, u32 vb);
    void vsr(u32 vd, u32 va, u32 vb);
    void vsrab(u32 vd, u32 va, u32 vb);
    void vsrah(u32 vd, u32 va, u32 vb);
    void vsraw(u32 vd, u32 va, u32 vb);
    void vsrb(u32 vd, u32 va, u32 vb);
    void vsrh(u32 vd, u32 va, u32 vb);
    void vsro(u32 vd, u32 va, u32 vb);
    void vsrw(u32 vd, u32 va, u32 vb);
    void vsubcuw(u32 vd, u32 va, u32 vb);
    void vsubfp(u32 vd, u32 va, u32 vb);
    void vsubsbs(u32 vd, u32 va, u32 vb);
    void vsubshs(u32 vd, u32 va, u32 vb);
    void vsubsws(u32 vd, u32 va, u32 vb);
    void vsububm(u32 vd, u32 va, u32 vb);
    void vsububs(u32 vd, u32 va, u32 vb);
    void vsubuhm(u32 vd, u32 va, u32 vb);
    void vsubuhs(u32 vd, u32 va, u32 vb);
    void vsubuwm(u32 vd, u32 va, u32 vb);
    void vsubuws(u32 vd, u32 va, u32 vb);
    void vsum2sws(u32 vd, u32 va, u32 vb);
    void vsum4sbs(u32 vd, u32 va, u32 vb);
    void vsum4shs(u32 vd, u32 va, u32 vb);
    void vsum4ubs(u32 vd, u32 va, u32 vb);
    void vsumsws(u32 vd, u32 va, u32 vb);
    void vupkhpx(u32 vd, u32 vb);
    void vupkhsb(u32 vd, u32 vb);
    void vupkhsh(u32 vd, u32 vb);
    void vupklpx(u32 vd, u32 vb);
    void vupklsb(u32 vd, u32 vb);
    void vupklsh(u32 vd, u32 vb);
    void vxor(u32 vd, u32 va, u32 vb);

    // Unknown instruction
    void unknown(u32 instruction);
    void unknown(const std::string& instruction);
};