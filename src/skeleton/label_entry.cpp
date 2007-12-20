// ライセンス: GPL2

//#define _DEBUG
#include "jddebug.h"

#include "label_entry.h"
#include "view.h"

using namespace SKELETON;


LabelEntry::LabelEntry( const bool editable, const std::string& label, const std::string& text )
    : m_editable( editable )
{
    m_label.set_text_with_mnemonic( label );
    m_label.set_mnemonic_widget ( m_entry );

    m_info.set_size_request( 0, 0 );
    m_info.set_alignment( Gtk::ALIGN_LEFT );

    setup();
    set_text( text );
}


void LabelEntry::setup()
{
    pack_start( m_label, Gtk::PACK_SHRINK );

    if( m_editable ) pack_start( m_entry );
    else pack_start( m_info );

    show_all();
}


void LabelEntry::set_editable( const bool editable )
{
#ifdef _DEBUG
    std::cout << "LabelEntry::set_editable editable = " << editable << std::endl;
#endif

    remove( m_label );
    if( m_editable ) remove( m_entry );
    else remove( m_info );

    m_editable = editable;
    setup();
}


void LabelEntry::set_visibility( bool visibility )
{
    if( m_editable ) m_entry.set_visibility( visibility );
}


void LabelEntry::set_text( const std::string& text )
{
    m_entry.set_text( text );
    m_info.set_text( text );
}


const Glib::ustring LabelEntry::get_text()
{
    if( m_editable ) return m_entry.get_text();
    return m_info.get_text();
}


void LabelEntry::grab_focus()
{
    if( m_editable ) m_entry.grab_focus();
}


const bool LabelEntry::has_grab()
{
    if( m_editable ) return m_entry.has_grab();
    return false;
}
