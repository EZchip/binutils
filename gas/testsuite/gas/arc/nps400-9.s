        .text

        ;; dcmac
        dcmac r0,[cm:r0],[cm:r0],r0
        dcmac r2,[cm:r4],[cm:r4],r7
        dcmac r31,[cm:r31],[cm:r31],r31

        dcmac r0,[cm:r0],[cm:0x0],r0
        dcmac r2,[cm:r4],[cm:0x1234],r7
        dcmac r31,[cm:r31],[cm:0xffff],r31

        dcmac r0,[cm:0x0],[cm:r0],r0
        dcmac r2,[cm:0x4321],[cm:r4],r7
        dcmac r31,[cm:0xffff],[cm:r31],r31

        dcmac 0,[cm:r0],[cm:r0],r0
        dcmac 0,[cm:r4],[cm:r4],r7
        dcmac 0,[cm:r31],[cm:r31],r31

        dcmac 0,[cm:r0],[cm:0x0],r0
        dcmac 0,[cm:r4],[cm:0x1234],r7
        dcmac 0,[cm:r31],[cm:0xffff],r31

        dcmac 0,[cm:0x0],[cm:r0],r0
        dcmac 0,[cm:0x4321],[cm:r4],r7
        dcmac 0,[cm:0xffff],[cm:r31],r31

        dcmac r0,[cm:r0],[cm:r0],1
        dcmac r2,[cm:r4],[cm:r4],0xf
        dcmac r31,[cm:r31],[cm:r31],0x1f

        dcmac r0,[cm:r0],[cm:0x0],1
        dcmac r2,[cm:r4],[cm:0x1234],0xf
        dcmac r31,[cm:r31],[cm:0xffff],0x1e

        dcmac r0,[cm:0x0],[cm:r0],1
        dcmac r2,[cm:0x4321],[cm:r4],0xf
        dcmac r31,[cm:0xffff],[cm:r31],0x1e

        dcmac 0,[cm:r0],[cm:r0],1
        dcmac 0,[cm:r4],[cm:r4],0xf
        dcmac 0,[cm:r31],[cm:r31],0x1e

        dcmac 0,[cm:r0],[cm:0x0],1
        dcmac 0,[cm:r4],[cm:0x1234],0xf
        dcmac 0,[cm:r31],[cm:0xffff],0x20

        dcmac 0,[cm:0x0],[cm:r0],1
        dcmac 0,[cm:0x4321],[cm:r4],0xf
        dcmac 0,[cm:0xffff],[cm:r31],0x20

        dcipv4 r2,[cm:r4],[cm:r4],r7
        dcipv4 r2,[cm:r4],[cm:0x1234],r7
        dcipv4 r2,[cm:0x8765],[cm:r4],r7
        dcipv4 r2,[cm:r4],[cm:r4],r7, 0x14
        dcipv4 r2,[cm:r4],[cm:0x1234],r7, 0x14
        dcipv4 r2,[cm:0x8765],[cm:r4],r7, 0x14

        dcipv4 0,[cm:r4],[cm:r4],r7
        dcipv4 0,[cm:r4],[cm:0x1234],r7
        dcipv4 0,[cm:0x8765],[cm:r4],r7
        dcipv4 0,[cm:r4],[cm:r4],r7, 0x14
        dcipv4 0,[cm:r4],[cm:0x1234],r7, 0x14
        dcipv4 0,[cm:0x8765],[cm:r4],r7, 0x14

        dcipv6 r2,[cm:r4],[cm:r4],r7
        dcipv6 r2,[cm:r4],[cm:0x1234],r7
        dcipv6 r2,[cm:0x8765],[cm:r4],r7
        dcipv6 r2,[cm:r4],[cm:r4],r7, 0x14
        dcipv6 r2,[cm:r4],[cm:0x1234],r7, 0x14
        dcipv6 r2,[cm:0x8765],[cm:r4],r7, 0x14

        dcipv6 0,[cm:r4],[cm:r4],r7
        dcipv6 0,[cm:r4],[cm:0x1234],r7
        dcipv6 0,[cm:0x8765],[cm:r4],r7
        dcipv6 0,[cm:r4],[cm:r4],r7, 0x14
        dcipv6 0,[cm:r4],[cm:0x1234],r7, 0x14
        dcipv6 0,[cm:0x8765],[cm:r4],r7, 0x14

        dcmpls r2,[cm:r4],[cm:r4],r7
        dcmpls r2,[cm:r4],[cm:0x1234],r7
        dcmpls r2,[cm:0x8765],[cm:r4],r7
        dcmpls r2,[cm:r4],[cm:r4], 0x10
        dcmpls r2,[cm:r4],[cm:0x1234], 0x10
        dcmpls r2,[cm:0x8765],[cm:r4], 0x10

        dcmpls 0,[cm:r4],[cm:r4],r7
        dcmpls 0,[cm:r4],[cm:0x1234],r7
        dcmpls 0,[cm:0x8765],[cm:r4],r7
        dcmpls 0,[cm:r4],[cm:r4], 0x10
        dcmpls 0,[cm:r4],[cm:0x1234], 0x10
        dcmpls 0,[cm:0x8765],[cm:r4], 0x10

        dcsmpls r2,[cm:r4],[cm:r4],r7
        dcsmpls r2,[cm:r4],[cm:0x1234],r7
        dcsmpls r2,[cm:0x8765],[cm:r4],r7
        dcsmpls r2,[cm:r4],[cm:r4], 0x8
        dcsmpls r2,[cm:r4],[cm:0x1234], 0x8
        dcsmpls r2,[cm:0x8765],[cm:r4], 0x8

        dcsmpls 0,[cm:r4],[cm:r4],r7
        dcsmpls 0,[cm:r4],[cm:0x1234],r7
        dcsmpls 0,[cm:0x8765],[cm:r4],r7
        dcsmpls 0,[cm:r4],[cm:r4], 0x8
        dcsmpls 0,[cm:r4],[cm:0x1234], 0x8
        dcsmpls 0,[cm:0x8765],[cm:r4], 0x8

        ; use cmem full address
        dcmac r2,[cm:r4],[cm:0x57f00024],r7
        dcmac r2,[cm:0x57f0000c],[cm:r4],r7
        dcmac r2,[cm:r4],[cm:0x57f00024],0x14
        dcmac r2,[cm:0x57f0000c],[cm:r4],0x14

        dcipv4 r2,[cm:r4],[cm:0x57f00024],r7
        dcipv4 r2,[cm:0x57f0000c],[cm:r4],r7
        dcipv4 r2,[cm:r4],[cm:0x57f00024],r7, 0x14
        dcipv4 r2,[cm:0x57f0000c],[cm:r4],r7, 0x14

        dcipv6 r2,[cm:r4],[cm:0x57f00024],r7
        dcipv6 r2,[cm:0x57f0000c],[cm:r4],r7
        dcipv6 r2,[cm:r4],[cm:0x57f00024],r7, 0x14
        dcipv6 r2,[cm:0x57f0000c],[cm:r4],r7, 0x14

        dcmpls r2,[cm:r4],[cm:0x57f00024],r7
        dcmpls r2,[cm:0x57f0000c],[cm:r4],r7
        dcmpls r2,[cm:r4],[cm:0x57f00024],0x10
        dcmpls r2,[cm:0x57f0000c],[cm:r4],0x10

        dcsmpls r2,[cm:r4],[cm:0x57f00024],r7
        dcsmpls r2,[cm:0x57f0000c],[cm:r4],r7
        dcsmpls r2,[cm:r4],[cm:0x57f00024],0x8
        dcsmpls r2,[cm:0x57f0000c],[cm:r4],0x8
