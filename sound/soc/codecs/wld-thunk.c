#include <plat/board.h>

#if defined(CONFIG_SND_RK29_SOC_RT3261) || defined(CONFIG_SND_RK29_SOC_RT3224)
extern void codec_set_spk_rt3261(bool on);
#endif

#if defined(CONFIG_MFD_RK616)
extern void codec_set_spk_rk616(bool on);
#endif

void codec_set_spk(bool on)
{
	if (board_use_rk616_codec()) {
		#if defined(CONFIG_MFD_RK616)
			codec_set_spk_rk616(on);
		#endif
	} else {
		#if defined(CONFIG_SND_RK29_SOC_RT3261) || defined(CONFIG_SND_RK29_SOC_RT3224)
			codec_set_spk_rt3261(on);
		#endif
	}
}