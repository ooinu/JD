// ライセンス: GPL2

//#define _DEBUG
#include "jddebug.h"

#include "sidebaritempref.h"

#include "jdlib/miscutil.h"

#include "global.h"
#include "session.h"

using namespace CORE;

SidebarItemPref::SidebarItemPref( Gtk::Window* parent, const std::string& url )
    : SKELETON::SelectItemPref( parent, url )
{
    // 項目設定
    append_hidden( ITEM_NAME_SEARCHBOX );
    append_hidden( ITEM_NAME_SEARCH_NEXT );
    append_hidden( ITEM_NAME_SEARCH_PREV );

    std::string order = SESSION::get_items_sidebar_str();
    std::list< std::string > list_order = MISC::split_line( order );
    std::list< std::string >::iterator it = list_order.begin();
    for( ; it != list_order.end(); ++it ){
        append_shown( *it );
        erase_hidden( *it );
    }

    set_label( "以下の設定は次回起動時から適用されます。" );
    set_title( "ツールバー項目設定(サイドバー)" );
}


// OKを押した
void SidebarItemPref::slot_ok_clicked()
{
    SESSION::set_items_sidebar_str( get_items() );
}


// デフォルトボタン
void SidebarItemPref::slot_def()
{
    clear();

    // 項目設定
    append_shown( ITEM_NAME_SEARCHBOX );
    append_shown( ITEM_NAME_SEARCH_NEXT );
    append_shown( ITEM_NAME_SEARCH_PREV );
}