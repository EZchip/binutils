        .text

        /* dctcp */
        dctcp   r10, r12

        /* dcip */
        dcip    r13, r14, r15
        dcip    r13, r14
        dcip    r13, r14, 0x44,0x88,0x11, 0x22

        /* dcet */
        dcet    r16, r17
        dcet    r18, r19, r20
        dcet    r18,r19,0x1234,0x4321
