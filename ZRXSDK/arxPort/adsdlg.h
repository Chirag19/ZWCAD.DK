
#ifndef _ARXPORT_AD_ADSDLG_H_
#define _ARXPORT_AD_ADSDLG_H_ 1


#include "ads.h"
#include "AdAChar.h"
#include "..\inc\zdsdlg.h"

typedef zds_hdlg				ads_hdlg;
typedef zds_htile				ads_htile;
typedef zds_callback_packet		ads_callback_packet;

#define CBR_SELECT			ZCBR_SELECT
#define CBR_LOST_FOCUS		ZCBR_LOST_FOCUS
#define CBR_DRAG			ZCBR_DRAG
#define CBR_DOUBLE_CLICK	ZCBR_DOUBLE_CLICK

#define ads_load_dialog				zds_load_dialog
#define ads_unload_dialog			zds_unload_dialog
#define ads_new_dialog				zds_new_dialog
#define ads_new_positioned_dialog	zds_new_positioned_dialog
#define ads_start_dialog			zds_start_dialog
#define ads_term_dialog				zds_term_dialog
#define ads_action_tile				zds_action_tile
#define ads_done_dialog				zds_done_dialog
#define ads_done_positioned_dialog	zds_done_positioned_dialog
#define ads_set_tile				zds_set_tile
#define ads_client_data_tile		zds_client_data_tile
#define ads_get_tile				zds_get_tile
#define ads_get_attr				zds_get_attr
#define ads_get_attr_string			zds_get_attr_string
#define ads_start_list				zds_start_list
#define ads_add_list				zds_add_list
#define ads_end_list				zds_end_list
#define ads_mode_tile				zds_mode_tile	
#define ads_dimensions_tile			zds_dimensions_tile
#define ads_start_image				zds_start_image
#define ads_vector_image			zds_vector_image
#define ads_fill_image				zds_fill_image
#define ads_slide_image				zds_slide_image
#define ads_end_image				zds_end_image		

#endif
