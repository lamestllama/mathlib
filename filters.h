/*
 * This file is part of mathlib.
 *
 * Copyright (C) 2010-2011 Greg Horn <ghorn@stanford.edu>
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

/*
 * filters.h
 */

#ifndef __FILTERS_H__
#define __FILTERS_H__

#include "xyz.h"

typedef struct {
  double kp;
  double ki;
  double kd;
  double integral_bound;
} pid_conf_t;

#ifdef __cplusplus
extern "C"{
#endif

  void simple_lowpass(double dt, double tau, double *state, double input);

  void xyz_simple_lowpass(double dt, double tau, xyz_t * state, const xyz_t * const input);

  double simple_pid(double y,
                    double y_dot,
                    double r,
                    double r_dot,
                    double dt,
                    double *i_state,
                    pid_conf_t *c);

#ifdef __cplusplus
}
#endif

#endif //__FILTERS_H__
