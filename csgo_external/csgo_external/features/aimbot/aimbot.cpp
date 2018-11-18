#include "aimbot.h"
using namespace sdk;
namespace features {
	namespace aimbot {
		caimbot* c_aimbot = new caimbot();
		caimbot::caimbot() {
			best_target = 1;
		}
		bool caimbot::valid_target(std::auto_ptr<sdk::centity> target) {
			if (target->is_dormant())
				return false;
			if (target->get_health() <= 0)
				return false;
			if (target->ent == globals::local->ent)
				return false;
			if (target->get_immunity())
				return false;
			return true;
		}
		void caimbot::get_target(vec3 viewang, vec3 vecorigin, vec3 vecoffset, vec3 punch, bool rcs, float rcsx,float rcsy, int bone) {
			auto best = FLT_MAX;
			for (int i = 1; i <= 64; i++) {
				auto target = csgo::c_client->get_entity(i);
				if (target->is_dormant())
					continue;
				if (target->get_health() <= 0)
					continue;
				if (target->ent == globals::local->ent)
					continue;
				if (target->get_immunity())
					continue;
				auto closet = c_math->get_fov(viewang, vecorigin, target->get_bone_position(bone), vecoffset, punch, rcs, rcsx,rcsy);
				if (closet < best) {
					best = closet;
					best_target = i;
				}
			}
		}
		void caimbot::think() {
			if (globals::weapon->abwpn()) {
				auto target = csgo::c_client->get_entity(best_target);
				//if (!valid_target(target))
				//	best_target = -1;
				auto id = globals::weapon->id();
				if (wpn_t[id].aimbot) {
					auto shots = globals::local->get_shots_fired();
					if (shots >= wpn_t[id].shots_ignore) {
						if (GetAsyncKeyState(wpn_t[id].aimbot_key1) || GetAsyncKeyState(wpn_t[id].aimbot_key2)) {
							auto view_ang = csgo::c_engine->get_viewang();
							auto origin = globals::local->get_vec_origin();
							auto offset = globals::local->get_vec_offset();
							auto punch = globals::local->get_punch_angle();
							auto bone = shots <= wpn_t[id].shots_bone_change ? wpn_t[id].first_bone : wpn_t[id].second_bone;
							get_target(view_ang, origin, offset, punch, wpn_t[id].rcs, c_math->rnd_float(wpn_t[id].rcs_x_min, wpn_t[id].rcs_x_max), c_math->rnd_float(wpn_t[id].rcs_y_min, wpn_t[id].rcs_y_max), bone);
							auto bone_position = target->get_bone_position(bone);
							auto fov = c_math->get_fov(view_ang, origin, bone_position, offset, punch, wpn_t[id].rcs, c_math->rnd_float(wpn_t[id].rcs_x_min, wpn_t[id].rcs_x_max), c_math->rnd_float(wpn_t[id].rcs_y_min, wpn_t[id].rcs_y_max));
							if (fov <= c_math->rnd_float(wpn_t[id].fov_min, wpn_t[id].fov_max)) {
								auto temp_angle = c_math->calc_ang(origin, bone_position, offset, punch, wpn_t[id].rcs, c_math->rnd_float(wpn_t[id].rcs_x_min, wpn_t[id].rcs_x_max), c_math->rnd_float(wpn_t[id].rcs_y_min, wpn_t[id].rcs_y_max));
								auto end_angle = [](vec3 calced_angle,bool curve, float curve_x, float curve_y, float smooth_x,float smooth_y, vec3 view_angle)->vec3 {
									if (curve) {
										auto curved_delta = calced_angle - view_angle;
										curved_delta += vec3(curved_delta.y / curve_y, curved_delta.x / curve_x, curved_delta.z);
										calced_angle = view_angle + curved_delta;
									}
									auto smoothed_delta = view_angle - calced_angle;
									calced_angle.x = view_angle.x - smoothed_delta.x / smooth_x;
									calced_angle.y = view_angle.y - smoothed_delta.y / smooth_y;
									calced_angle.z = 0;
									return calced_angle;
								}(temp_angle, wpn_t[id].humanization, c_math->rnd_float(wpn_t[id].humanization_x_min, wpn_t[id].humanization_x_max), c_math->rnd_float(wpn_t[id].humanization_y_min, wpn_t[id].humanization_y_max), c_math->rnd_float(wpn_t[id].smooth_x_min, wpn_t[id].smooth_x_max), c_math->rnd_float(wpn_t[id].smooth_y_min, wpn_t[id].smooth_y_max), view_ang);
								if (end_angle.is_valid()) {
									csgo::c_engine->set_viewang(end_angle.clamp());
								}
							}
						}
					}
				}
			}
		}
	}
}