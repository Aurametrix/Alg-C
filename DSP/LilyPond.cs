\version "2.19.22"

\include "english.ly"

\header {
  title = \markup { "Excerpt from" \italic "fibonacci" }
  composer = "Patrick McCarty"
  %  copyright = \markup \fontsize #-5 
  %  {
  %    Copyright © 2009.
  %    Typeset with GNU LilyPond.
  %    Released into public domain by the composer.
  %  }
}

\paper {
  paper-height = 4.6\in
  paper-width = 8.5\in
  indent = #0
  system-count = #2
}

\score {
  \new PianoStaff = "pianostaff" <<
    \new Staff = "RH" \relative c' {
      \accidentalStyle Score.piano
      \clef "treble"
      \time 2/4
      \set Score.currentBarNumber = #51
      \tempo "Slow and steady" 4 = 60
      <e gs,>4 \acciaccatura { cs16[ ds] } <e gs,>4 | % m. 51
      <ds gs,>4 \acciaccatura { e16[ ds] } <cs gs>4 | % m. 52
      <cs gs>4 \acciaccatura { ds16[ cs] } <c g>4  | % m. 53
      <cs gs>4 \acciaccatura { ds16[ e] } <es bs gs>4 | % m. 54

      <e gs,>4 \acciaccatura { cs16[ ds] } e16 f gs a | % m. 55
      <gs c,>8 \acciaccatura { as16[ gs] }
      <es b>8 ~ <es b>16 ds b as | % m. 56

      b16 d8 bf32 f' g16 af bf c | % m. 57
      <df df,>16 ( c af ) <e' e,> ( ds b ) <g' g,> ( ds | % m. 58

      \time 3/4
      <gs gs,>16 ) \noBeam d,16 f gs
      a16 e f b
      c16 d, ( f gs | % m. 59

      a16 b ) e, ( f
      gs16 b c ) f, (
      gs16 as b c ) | % m. 60
    }

    \new Dynamics = "Dynamics_pf" {
      s4 \p \< s4 | % m. 51
      s4 s4 | % m. 52
      s4 \mp \> s4 | % m. 53
      s4 s4 \! | % m. 54
      s4 \p s4 | % m. 55
      s1 * 2/4 | % m. 56
      s4 \< s4 | % m. 57
      s4 s4 | % m. 58
      \override DynamicText.extra-spacing-width = #'(-0.75 . 0.75)
      s16 \mf s16 \p s8 s4 s4 | % m. 59
      s2. | % m. 60
    }

    \new Staff = "LH" \relative c, {
      \clef "bass"
      \time 2/4
      cs4. cs8 | % m. 51
      cs4. d8 | % m. 52
      f4. a8 | % m. 53
      f4. d8 | % m. 54

      cs4. cs8 | % m. 55
      d4 ds | % m. 56
      gs4. bf,8 | % m. 57
      f'4 b, | % m. 58

      \time 3/4
      d4. d8 ~ d4 | % m. 59
      ef2 f4 | % m. 60
    }
  >>
}
