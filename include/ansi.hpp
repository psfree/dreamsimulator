#ifndef ANSI_HPP_INCLUDED
#define ANSI_HPP_INCLUDED

#include <string>
#include <boost/format.hpp>
#include <boost/algorithm/clamp.hpp>

namespace ansi {

    ///////////////
    //// Style ////
    ///////////////

    // Reset (0)
    std::string reset()
    {
        return std::string("\033[0m");
    }

    // Bold (1)
    std::string bold()
    {
        return std::string("\033[1m");
    }

    // Faint (2)
    std::string faint()
    {
        return std::string("\033[2m");
    }

    // Italic (3)
    std::string italic()
    {
        return std::string("\033[3m");
    }

    // Underline (4)
    std::string underline()
    {
        return std::string("\033[4m");
    }

    // Slow Blink (5)
    std::string slow_blink()
    {
        return std::string("\033[5m");
    }

    // Rapid Blink (6)
    std::string rapid_blink()
    {
        return std::string("\033[6m");
    }

    // Invert/Reverse Video (Swap FG & BG colours) (7)
    std::string invert()
    {
        return std::string("\033[7m");
    }

    // Conceal/Hide (Not widely supported) (8)
    std::string conceal()
    {
        return std::string("\033[8m");
    }

    // Strike Through (9)
    std::string strike()
    {
        return std::string("\033[9m");
    }

    // Primary Font (10)
    std::string primary_font()
    {
        return std::string("\033[10m");
    }

    // Alternative Font (11-19)
    // font: (0-9)
    std::string alternative_font(unsigned short int font)
    {
        return (boost::format("\033[%1%m") % (11 + boost::algorithm::clamp(font, 0, 9))).str();
    }

    // Fraktur (Type of font, rarely supported) (20)
    std::string fraktur()
    {
        return std::string("\033[20m");
    }

    // Double Underline (21)
    std::string double_underline()
    {
        return std::string("\033[21m");
    }

    // Normal Intensity (Neither bold nor faint) (22)
    std::string normal_intensity()
    {
        return std::string("\033[22m");
    }

    // Remove Italic (Remove italics and Fraktur) (23)
    std::string remove_italic()
    {
        return std::string("\033[23m");
    }

    // Remove Underline (24)
    std::string remove_underline()
    {
        return std::string("\033[24m");
    }

    // Remove Blink (25)
    std::string remove_blink()
    {
        return std::string("\033[25m");
    }

    // Proportional Spacing (Not know to be used in terminals) (26)
    std::string proportional_spacing()
    {
        return std::string("\033[26m");
    }

    // Invert Off (27)
    std::string invert_off()
    {
        return std::string("\033[27m");
    }

    // Reveal (Conceal off) (28)
    std::string reveal()
    {
        return std::string("\033[28m");
    }

    // Remove Strike (29)
    std::string remove_strike()
    {
        return std::string("\033[29m");
    }

    // FG Black (30)
    std::string fg_black()
    {
        return std::string("\033[30m");
    }

    // FG Red (31)
    std::string fg_red()
    {
        return std::string("\033[31m");
    }

    // FG Green (32)
    std::string fg_green()
    {
        return std::string("\033[32m");
    }

    // FG Yellow (33)
    std::string fg_yellow()
    {
        return std::string("\033[33m");
    }

    // FG Blue (34)
    std::string fg_blue()
    {
        return std::string("\033[34m");
    }

    // FG Magenta (35)
    std::string fg_magenta()
    {
        return std::string("\033[35m");
    }

    // FG Cyan (36)
    std::string fg_cyan()
    {
        return std::string("\033[36m");
    }

    // FG White (37)
    std::string fg_white()
    {
        return std::string("\033[37m");
    }

    // FG Custom (8-bit, from predefined list of 256 colours) (38)
    // colour: (0-255)
    std::string fg_custom(unsigned short int colour)
    {
        return (boost::format("\033[38;5;%1%m") % (boost::algorithm::clamp(colour, 0, 255))).str();
    }

    // FG Custom (RGB) (38)
    // red: (0-255)
    // green: (0-255)
    // blue: (0-255)
    std::string fg_custom(unsigned short int red, unsigned short int green, unsigned short int blue)
    {
        return (boost::format("\033[38;2;%1%;%2%;%3%m") % (boost::algorithm::clamp(red, 0, 255)) % (boost::algorithm::clamp(green, 0, 255)) % (boost::algorithm::clamp(blue, 0, 255))).str();
    }

    // FG Default (39)
    std::string fg_default()
    {
        return std::string("\033[39m");
    }

    // BG Black (40)
    std::string bg_black()
    {
        return std::string("\033[40m");
    }

    // BG Red (41)
    std::string bg_red()
    {
        return std::string("\033[41m");
    }

    // BG Green (42)
    std::string bg_green()
    {
        return std::string("\033[42m");
    }

    // BG Yellow (43)
    std::string bg_yellow()
    {
        return std::string("\033[43m");
    }

    // BG Blue (44)
    std::string bg_blue()
    {
        return std::string("\033[44m");
    }

    // BG Magenta (45)
    std::string bg_magenta()
    {
        return std::string("\033[45m");
    }

    // BG Cyan (46)
    std::string bg_cyan()
    {
        return std::string("\033[46m");
    }

    // BG White (47)
    std::string bg_white()
    {
        return std::string("\033[47m");
    }

    // BG Custom (8-bit, from predefined list of 256 colours) (48)
    // colour: (0-255)
    std::string bg_custom(unsigned short int colour)
    {
        return (boost::format("\033[48;5;%1%m") % (boost::algorithm::clamp(colour, 0, 255))).str();
    }

    // BG Custom (RGB) (48)
    // red: (0-255)
    // green: (0-255)
    // blue: (0-255)
    std::string bg_custom(unsigned short int red, unsigned short int green, unsigned short int blue)
    {
        return (boost::format("\033[48;2;%1%;%2%;%3%m") % (boost::algorithm::clamp(red, 0, 255)) % (boost::algorithm::clamp(green, 0, 255)) % (boost::algorithm::clamp(blue, 0, 255))).str();
    }

    // BG Default (49)
    std::string bg_default()
    {
        return std::string("\033[49m");
    }

    // Disable Proprotional Spacing (50)
    std::string disable_proportional_spacing()
    {
        return std::string("\033[50m");
    }

    // Framed (51)
    std::string framed()
    {
        return std::string("\033[51m");
    }

    // Encircled (52)
    std::string encircled()
    {
        return std::string("\033[52m");
    }

    // Overlined (53)
    std::string overlined()
    {
        return std::string("\033[53m");
    }

    // Remove Frame (Remove frame or circle) (54)
    std::string remove_frame()
    {
        return std::string("\033[54m");
    }

    // Remove Overline (55)
    std::string remove_overline()
    {
        return std::string("\033[55m");
    }

    // 56-57 not used

    // Underline Colour (8-bit, from predefined list of 256 colours) (58)
    // colour: (0-255)
    std::string underline_colour(unsigned short int colour)
    {
        return (boost::format("\033[58;5;%1%m") % (boost::algorithm::clamp(colour, 0, 255))).str();
    }

    // Underline Colour (RGB) (58)
    // red: (0-255)
    // green: (0-255)
    // blue: (0-255)
    std::string underline_colour(unsigned short int red, unsigned short int green, unsigned short int blue)
    {
        return (boost::format("\033[58;2;%1%;%2%;%3%m") % (boost::algorithm::clamp(red, 0, 255)) % (boost::algorithm::clamp(green, 0, 255)) % (boost::algorithm::clamp(blue, 0, 255))).str();
    }

    // Underline Default (Set underline colour to default) (59)
    std::string underline_default()
    {
        return std::string("\033[59m");
    }

    // Ideogram Underline (Rarely Supported) (60)
    std::string ideogram_underline()
    {
        return std::string("\033[60m");
    }

    // Right Line (60)
    std::string right_line()
    {
        return std::string("\033[60m");
    }

    // Ideogram Double Underline (Rarely Supported) (61)
    std::string ideogram_double_underline()
    {
        return std::string("\033[61m");
    }

    // Right Double Line (61)
    std::string right_double_line()
    {
        return std::string("\033[61m");
    }

    // Ideogram Overline (Rarely Supported) (62)
    std::string ideogram_overline()
    {
        return std::string("\033[62m");
    }

    // Left Line (62)
    std::string left_line()
    {
        return std::string("\033[62m");
    }

    // Ideogram Double Overline (Rarely Supported) (63)
    std::string ideogram_double_overline()
    {
        return std::string("\033[63m");
    }

    // Left Double Line (63)
    std::string left_double_line()
    {
        return std::string("\033[63m");
    }

    // Ideogram Stress Marking (Rarely Supported) (64)
    std::string ideogram_stress_marking()
    {
        return std::string("\033[64m");
    }

    // Ideogram Attributes Off (Rarely Supported) (65)
    std::string ideogram_attributes_off()
    {
        return std::string("\033[65m");
    }

    // 66-72 not used

    // Superscript (73)
    std::string superscript()
    {
        return std::string("\033[73m");
    }

    // Subscript (74)
    std::string subscript()
    {
        return std::string("\033[74m");
    }

    // 75-89 not used

    // FG Bright Black (Grey) (90)
    std::string fg_bright_black()
    {
        return std::string("\033[90m");
    }

    // FG Bright Red (91)
    std::string fg_bright_red()
    {
        return std::string("\033[91m");
    }

    // FG Bright Green (92)
    std::string fg_bright_green()
    {
        return std::string("\033[92m");
    }

    // FG Bright Yellow (93)
    std::string fg_bright_yellow()
    {
        return std::string("\033[93m");
    }

    // FG Bright Blue (94)
    std::string fg_bright_blue()
    {
        return std::string("\033[94m");
    }

    // FG Bright Magenta (95)
    std::string fg_bright_magenta()
    {
        return std::string("\033[95m");
    }

    // FG Bright Cyan (96)
    std::string fg_bright_cyan()
    {
        return std::string("\033[96m");
    }

    // FG Bright White (97)
    std::string fg_bright_white()
    {
        return std::string("\033[97m");
    }

    // 98-99 not used

    // BG Bright Black (100)
    std::string bg_bright_black()
    {
        return std::string("\033[100m");
    }

    // BG Bright Red (101)
    std::string bg_bright_red()
    {
        return std::string("\033[101m");
    }

    // BG Bright Green (102)
    std::string bg_bright_green()
    {
        return std::string("\033[102m");
    }

    // BG Bright Yellow (103)
    std::string bg_bright_yellow()
    {
        return std::string("\033[103m");
    }

    // BG Bright Blue (104)
    std::string bg_bright_blue()
    {
        return std::string("\033[104m");
    }

    // BG Bright Magenta (105)
    std::string bg_bright_magenta()
    {
        return std::string("\033[105m");
    }

    // BG Bright Cyan (106)
    std::string bg_bright_cyan()
    {
        return std::string("\033[106m");
    }

    // BG Bright White (107)
    std::string bg_bright_white()
    {
        return std::string("\033[107m");
    }

    ///////////////
    //// Cursor ////
    ///////////////

    // Cursor Up
    std::string cursor_up(unsigned int n)
    {
        return (boost::format("\033[%1%A") % n).str();
    }

    // Cursor Down
    std::string cursor_down(unsigned int n)
    {
        return (boost::format("\033[%1%B") % n).str();
    }

    // Cursor Forward
    std::string cursor_forward(unsigned int n)
    {
        return (boost::format("\033[%1%C") % n).str();
    }

    // Cursor Back
    std::string cursor_back(unsigned int n)
    {
        return (boost::format("\033[%1%D") % n).str();
    }

    // Cursor Next Line
    std::string cursor_next_line(unsigned int n)
    {
        return (boost::format("\033[%1%E") % n).str();
    }

    // Cursor Previous Line
    std::string cursor_prev_line(unsigned int n)
    {
        return (boost::format("\033[%1%F") % n).str();
    }

    // Cursor Column
    std::string cursor_col(unsigned int n)
    {
        return (boost::format("\033[%1%G") % n).str();
    }

    // Cursor Position
    std::string cursor_pos(unsigned int row, unsigned int column)
    {
        return (boost::format("\033[%1%;%2%H") % row % column).str();
    }

    // Erase in Display
    std::string erase_in_display(unsigned int n = 0)
    {
        return (boost::format("\033[%1%J") % n).str();
    }

    // Erase in Line
    std::string erase_in_line(unsigned int n = 0)
    {
        return (boost::format("\033[%1%K") % n).str();
    }

    // Scroll Up
    std::string scroll_up(unsigned int n)
    {
        return (boost::format("\033[%1%S") % n).str();
    }

    // Scroll Down
    std::string scroll_down(unsigned int n)
    {
        return (boost::format("\033[%1%T") % n).str();
    }

    // Cursor Horizontal Vertical Position
    std::string cursor_hv_pos(unsigned int row, unsigned int column)
    {
        return (boost::format("\033[%1%;%2%f") % row % column).str();
    }

    // AUX Port On
    std::string aux_port_on()
    {
        return std::string("\033[5i");
    }

    // AUX Port Off
    std::string aux_port_off()
    {
        return std::string("\033[4i");
    }

    // Device Status Report (Reports cursor pos to application as input of "ESC[n;mR")
    std::string device_status_report()
    {
        return std::string("\033[6n");
    }

    // Save Current Cursor Position (Saves cursor position/state in SCO console mode)
    std::string save_cursor_pos()
    {
        return std::string("\033[s");
    }

    // Restore Saved Cursor Position (Restores cursor position in SCO console mode)
    std::string restore_cursor_pos()
    {
        return std::string("\033[s");
    }

    // Show Cursor
    std::string show_cursor()
    {
        return std::string("\033[?25h");
    }

    // Hide Cursor
    std::string hide_cursor()
    {
        return std::string("\033[?25l");
    }

    // Enable Alternative Screen Buffer
    std::string enable_alt_buffer()
    {
        return std::string("\033[?1049h");
    }

    // Disable Alterative Screen Buffer
    std::string disable_alt_buffer()
    {
        return std::string("\033[?1049l");
    }

    // Enable Bracketed Paste Mode
    std::string enable_bracketed_paste()
    {
        return std::string("\033[?2004h");
    }

    // Disable Bracketed Paste Mode
    std::string disable_bracketed_paste()
    {
        return std::string("\033[?2004l");
    }
} // ansi

#endif // ANSI_HPP_INCLUDED
