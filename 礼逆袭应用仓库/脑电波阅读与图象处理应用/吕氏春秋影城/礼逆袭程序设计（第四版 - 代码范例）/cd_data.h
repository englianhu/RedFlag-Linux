#include <ndbm.h>
#include <gdbm-ndbm.h>

/* 目录图表 */
#define CAT_CAT_LEN		30
#define CAT_TITLE_LEN	70
#define CAT_TYPE_LEN	30
#define CAT_ARTIST_LEN	70

typedef struct {
	char catalog[CAT_CAT_LEN + 1];
	char title[CAT_TITLE_LEN + 1];
	char type[CAT_TYPE_LEN + 1];
	char artist[CAT_ARTIST_LEN + 1];
} cdc_entry;

/* 歌曲图表，逐个输入歌曲 */
#define TRACK_CAT_LEN	CAT_CAT_LEN
#define TRACK_TTEXT_LEN	70

typedef struct {
	char catalog[TRACK_CAT_LEN + 1];
	int track_no;
	char track_txt[TRACK_TTEXT_LEN + 1];
} cdt_entry;

static int command_mode(int argc, char *argv[]);
static void announce(void);
static menu_options show_menu(const cdc_entry *current_cdc);
static int get_confirm(const char *question);
static int enter_new_cat_entry(const cdc_entry *entry_to_update);
static void enter_new_track_entries(const cdc_entry *entry_to_add_to);
static void del_cat_entry(const cdc_entry *entry_to_delete);
static void del_track_entries(const cdc_entry *entry_to_delete);
static cdc_entry find_cat(void);
static void list_tracks(const cdc_entry *entry_to_use);
static void count_all_entries(void);
static void display_cdc(const cdc_entry *cdc_to_show);
static void display_cdt(const cdt_entry *cdt_to_show);
static void strip_return(char *string_to_strip);

