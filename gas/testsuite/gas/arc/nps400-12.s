        .text

        ; Atomic operation instructions
        xex.di     r0,r0,[xa:r1]
        xex.di     r0,r0,[sd:r1]
        xex.di     r0,r0,[xd:r1]
        xex.di     r0,r0,[r1]

        ;exc{b,w}
        excb.di    r0,r0,[xa:r1]
        excb.di.f  r0,r0,[xa:r1]
        excb.di    r0,r0,[r1]
        excb.di.f  r0,r0,[r1]

        excw.di    r0,r0,[xa:r1]
        excw.di.f  r0,r0,[xa:r1]
        excw.di    r0,r0,[r1]
        excw.di.f  r0,r0,[r1]

        exc.di     r0,r0,[xa:r1]
        exc.di.f   r0,r0,[xa:r1]
        exc.di     r0,r0,[sd:r1]
        exc.di.f   r0,r0,[sd:r1]
        exc.di     r0,r0,[xd:r1]
        exc.di.f   r0,r0,[xd:r1]
        exc.di     r0,r0,[r1]
        exc.di.f   r0,r0,[r1]

        ;aabb{b,w,l}
        aaddb.di   r0,r0,[xa:r1]
        aaddb.di.f r0,r0,[xa:r1]
        aaddb.di   r0,r0,[r1]
        aaddb.di.f r0,r0,[r1]

        aaddb.di   r0,[xa:r1]
        aaddb.di   r0,[r1]

        aaddw.di   r0,r0,[xa:r1]
        aaddw.di.f r0,r0,[xa:r1]
        aaddw.di   r0,r0,[r1]
        aaddw.di.f r0,r0,[r1]
        aaddw.di   r0,r0,[mbd:r1]

        aaddw.di   r0,[xa:r1]
        aaddw.di   r0,[r1]
        aaddw.di   r0,[mbd:r1]

        aadd.di     r0,r0,[xa:r1]
        aadd.di.f   r0,r0,[xa:r1]
        aadd.di     r0,r0,[sd:r1]
        aadd.di.f   r0,r0,[sd:r1]
        aadd.di     r0,r0,[xd:r1]
        aadd.di.f   r0,r0,[xd:r1]
        aadd.di     r0,r0,[r1]
        aadd.di.f   r0,r0,[r1]

        aadd.di     r0,[xa:r1]
        aadd.di     r0,[sd:r1]
        aadd.di     r0,[xd:r1]
        aadd.di     r0,[r1]

        aaddl.di     r0,[xa:r1]
        aaddl.di     r0,[sd:r1]
        aaddl.di     r0,[xd:r1]
        aaddl.di     r0,[r1]

        ; adadd{l}
        adadd.di     r0,r0,[xa:r1]
        adadd.di.f   r0,r0,[xa:r1]
        adadd.di     r0,r0,[sd:r1]
        adadd.di.f   r0,r0,[sd:r1]
        adadd.di     r0,r0,[xd:r1]
        adadd.di.f   r0,r0,[xd:r1]
        adadd.di     r0,r0,[r1]
        adadd.di.f   r0,r0,[r1]

        adaddl.di     r0,r0,[xa:r1]
        adaddl.di.f   r0,r0,[xa:r1]
        adaddl.di     r0,r0,[sd:r1]
        adaddl.di.f   r0,r0,[sd:r1]
        adaddl.di     r0,r0,[xd:r1]
        adaddl.di.f   r0,r0,[xd:r1]
        adaddl.di     r0,r0,[r1]
        adaddl.di.f   r0,r0,[r1]

        adaddl.di r0, [xa:r1]
        adaddl.di r0, [xd:r1]
        adaddl.di r0, [r1]

        adadd.di     r0,[xa:r1]
        adadd.di     r0,[sd:r1]
        adadd.di     r0,[xd:r1]
        adadd.di     r0,[r1]

        ; aadnd{b,w}
        aand.di     r0,r0,[xa:r1]
        aand.di.f   r0,r0,[xa:r1]
        aand.di     r0,r0,[sd:r1]
        aand.di.f   r0,r0,[sd:r1]
        aand.di     r0,r0,[xd:r1]
        aand.di.f   r0,r0,[xd:r1]
        aand.di     r0,r0,[r1]
        aand.di.f   r0,r0,[r1]

        aandb.di     r0,r0,[xa:r1]
        aandb.di.f   r0,r0,[xa:r1]
        aandb.di     r0,r0,[r1]
        aandb.di.f   r0,r0,[r1]

        aandw.di     r0,r0,[xa:r1]
        aandw.di.f   r0,r0,[xa:r1]
        aandw.di     r0,r0,[r1]
        aandw.di.f   r0,r0,[r1]

        aandb.di     r0,[xa:r1]
        aandb.di     r0,[r1]

        aandw.di     r0,[xa:r1]
        aandw.di     r0,[r1]

        aand.di     r0,[xa:r1]
        aand.di     r0,[sd:r1]
        aand.di     r0,[xd:r1]
        aand.di     r0,[r1]

        ;aor{bw}
        aor.di     r0,r0,[xa:r1]
        aor.di.f   r0,r0,[xa:r1]
        aor.di     r0,r0,[sd:r1]
        aor.di.f   r0,r0,[sd:r1]
        aor.di     r0,r0,[xd:r1]
        aor.di.f   r0,r0,[xd:r1]
        aor.di     r0,r0,[r1]
        aor.di.f   r0,r0,[r1]

        aorb.di     r0,r0,[xa:r1]
        aorb.di.f   r0,r0,[xa:r1]
        aorb.di     r0,r0,[r1]
        aorb.di.f   r0,r0,[r1]

        aorw.di     r0,r0,[xa:r1]
        aorw.di.f   r0,r0,[xa:r1]
        aorw.di     r0,r0,[r1]
        aorw.di.f   r0,r0,[r1]

        aorb.di     r0,[xa:r1]
        aorb.di     r0,[r1]

        aorw.di     r0,[xa:r1]
        aorw.di     r0,[r1]

        aor.di     r0,[xa:r1]
        aor.di     r0,[sd:r1]
        aor.di     r0,[xd:r1]
        aor.di     r0,[r1]

        ;axor{bw}
        axor.di     r0,r0,[xa:r1]
        axor.di.f   r0,r0,[xa:r1]
        axor.di     r0,r0,[sd:r1]
        axor.di.f   r0,r0,[sd:r1]
        axor.di     r0,r0,[xd:r1]
        axor.di.f   r0,r0,[xd:r1]
        axor.di     r0,r0,[r1]
        axor.di.f   r0,r0,[r1]

        axorb.di     r0,r0,[xa:r1]
        axorb.di.f   r0,r0,[xa:r1]
        axorb.di     r0,r0,[r1]
        axorb.di.f   r0,r0,[r1]

        axorw.di     r0,r0,[xa:r1]
        axorw.di.f   r0,r0,[xa:r1]
        axorw.di     r0,r0,[r1]
        axorw.di.f   r0,r0,[r1]

        axorb.di     r0,[xa:r1]
        axorb.di     r0,[r1]

        axorw.di     r0,[xa:r1]
        axorw.di     r0,[r1]

        axor.di     r0,[xa:r1]
        axor.di     r0,[sd:r1]
        axor.di     r0,[xd:r1]
        axor.di     r0,[r1]

        ; atst{b,w}
        atstb.di    r0,[xa:r1]
        atstb.di.f  r0,[xa:r1]
        atstb.di    r0,[r1]
        atstb.di.f  r0,[r1]

        atstw.di    r0,[xa:r1]
        atstw.di.f  r0,[xa:r1]
        atstw.di    r0,[r1]
        atstw.di.f  r0,[r1]

        atst.di     r0,[xa:r1]
        atst.di.f   r0,[xa:r1]
        atst.di     r0,[sd:r1]
        atst.di.f   r0,[sd:r1]
        atst.di     r0,[xd:r1]
        atst.di.f   r0,[xd:r1]
        atst.di     r0,[r1]
        atst.di.f   r0,[r1]

        ; ari{b,w}
        arib.di     r0,[xa:r1]
        arib.di.f   r0,[xa:r1]
        arib.di     r0,[r1]
        arib.di.f   r0,[r1]

        ariw.di     r0,[xa:r1]
        ariw.di.f   r0,[xa:r1]
        ariw.di     r0,[r1]
        ariw.di.f   r0,[r1]
        ariw.di     r0, [mbd:r1]

        ari.di      r0,[xa:r1]
        ari.di.f    r0,[xa:r1]
        ari.di      r0,[sd:r1]
        ari.di.f    r0,[sd:r1]
        ari.di      r0,[xd:r1]
        ari.di.f    r0,[xd:r1]
        ari.di      r0,[r1]
        ari.di.f    r0,[r1]

        ; ardc{b,w}
        ardcb.di    r0,[xa:r1]
        ardcb.di.f  r0,[xa:r1]
        ardcb.di    r0,[r1]
        ardcb.di.f  r0,[r1]

        ardcw.di    r0,[xa:r1]
        ardcw.di.f  r0,[xa:r1]
        ardcw.di    r0,[r1]
        ardcw.di.f  r0,[r1]
        ardcw.di.f r0, [mbd:r1]

        ardc.di     r0,[xa:r1]
        ardc.di.f   r0,[xa:r1]
        ardc.di     r0,[sd:r1]
        ardc.di.f   r0,[sd:r1]
        ardc.di     r0,[xd:r1]
        ardc.di.f   r0,[xd:r1]
        ardc.di     r0,[r1]
        ardc.di.f   r0,[r1]

        ; aric
        aric.di     r0,[xa:r1]
        aric.di.f   r0,[xa:r1]
        aric.di     r0,[sd:r1]
        aric.di.f   r0,[sd:r1]
        aric.di     r0,[xd:r1]
        aric.di.f   r0,[xd:r1]
        aric.di     r0,[r1]
        aric.di.f   r0,[r1]

        ; arcl{b,w,l}
        arclb.di    r0,[xa:r1]
        arclb.di.f  r0,[xa:r1]
        arclb.di    r0,[r1]
        arclb.di.f  r0,[r1]

        arclw.di    r0,[xa:r1]
        arclw.di.f  r0,[xa:r1]
        arclw.di    r0,[r1]
        arclw.di.f  r0,[r1]

        arcl.di     r0,[xa:r1]
        arcl.di.f   r0,[xa:r1]
        arcl.di     r0,[sd:r1]
        arcl.di.f   r0,[sd:r1]
        arcl.di     r0,[xd:r1]
        arcl.di.f   r0,[xd:r1]
        arcl.di     r0,[r1]
        arcl.di.f   r0,[r1]

        ;xld{b,w}
        xld.di      r0,[xa:r1]
        xld.di      r0,[sd:r1]
        xld.di      r0,[xd:r1]
        xldb.di     r0,[xa:r1]
        xldw.di     r0,[xa:r1]
        xldw.di     r0,[mbd:r1]

        ;xst{b,w}
        xst.di      r0,[xa:r1]
        xst.di      r0,[sd:r1]
        xst.di      r0,[xd:r1]
        xstb.di     r0,[xa:r1]
        xstw.di     r0,[xa:r1]
        xstw.di     r0,[mbd:r1]
        xstl.di     r0,[xa:r1]
        xstl.di     r0,[mbd:r1]
label:
        ; aric.r
        aric.r.di     r0,[xa:r1]
        aric.r.di.f   r0,[xa:r1]
        aric.r.di     r0,[sd:r1]
        aric.r.di.f   r0,[sd:r1]
        aric.r.di     r0,[xd:r1]
        aric.r.di.f   r0,[xd:r1]
        aric.r.di     r0,[r1]
        aric.r.di.f   r0,[r1]

        ; bat
        bat label
