/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM topology

#define TRACE_INCLUDE_PATH trace/hooks

#if !defined(_TRACE_HOOK_TOPOLOGY_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_HOOK_TOPOLOGY_H

#include <trace/hooks/vendor_hooks.h>

struct cpumask;

DECLARE_HOOK(android_vh_arch_set_freq_scale,
	TP_PROTO(const struct cpumask *cpus, unsigned long freq, unsigned long max,
		unsigned long *scale),
	TP_ARGS(cpus, freq, max, scale));

DECLARE_RESTRICTED_HOOK(android_rvh_cpu_capacity_show,
	TP_PROTO(unsigned long *capacity, int cpu),
	TP_ARGS(capacity, cpu), 1);

#endif /* _TRACE_HOOK_TOPOLOGY_H */
/* This part must be outside protection */
#include <trace/define_trace.h>
