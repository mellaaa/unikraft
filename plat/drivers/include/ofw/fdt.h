/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * Authors: Wei Chen <Wei.Chen@arm.com>
 *          Jianyong Wu <Jianyong.Wu@arm.com>
 *
 * Copyright (c) 2018, Arm Ltd. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * THIS HEADER MAY NOT BE EXTRACTED OR MODIFIED IN ANY WAY.
 */
#ifndef _PLAT_DRIVER_OFW_FDT_H
#define _PLAT_DRIVER_OFW_FDT_H

#define FDT_BAD_ADDR (uint64_t)(-1)

/**
 * fdt_interrupt_cells - retrieve the number of cells needed to encode an
 *                       interrupt source
 * @fdt: pointer to the device tree blob
 * @nodeoffset: offset of the node to find the interrupt for.
 *
 * When the node has a valid #interrupt-cells property, returns its value.
 *
 * returns:
 *     0 <= n < FDT_MAX_NCELLS, on success
 *      -FDT_ERR_BADNCELLS, if the node has a badly formatted or invalid
 *             #interrupt-cells property
 *     -FDT_ERR_BADMAGIC,
 *     -FDT_ERR_BADVERSION,
 *     -FDT_ERR_BADSTATE,
 *     -FDT_ERR_BADSTRUCTURE,
 *     -FDT_ERR_TRUNCATED, standard meanings
 */
int fdt_interrupt_cells(const void *fdt, int nodeoffset);

/*
 * read and combine the big number of reg, caller needs to make sure size
 * is correct
 */
static inline uint64_t fdt_reg_read_number(const fdt32_t *regs, uint32_t size)
{
	uint64_t number = 0;

	for (uint32_t i = 0; i < size; i++) {
		number <<= 32;
		number |= fdt32_to_cpu(*regs);
		regs++;
	}

	return number;
}
#endif