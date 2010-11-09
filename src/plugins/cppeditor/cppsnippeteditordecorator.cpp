/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** Commercial Usage
**
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
**
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at http://qt.nokia.com/contact.
**
**************************************************************************/

#include "cppsnippeteditordecorator.h"
#include "cpphighlighter.h"
#include "cppeditor.h"
#include "cppqtstyleindenter.h"
#include "cppautocompleter.h"

#include <texteditor/texteditorsettings.h>
#include <texteditor/fontsettings.h>
#include <texteditor/texteditorconstants.h>
#include <texteditor/snippets/snippeteditor.h>

using namespace CppEditor;
using namespace Internal;

CppSnippetEditorDecorator::CppSnippetEditorDecorator() :
    TextEditor::ISnippetEditorDecorator()
{}

CppSnippetEditorDecorator::~CppSnippetEditorDecorator()
{}

bool CppSnippetEditorDecorator::supports(TextEditor::Snippet::Group group) const
{
    if (group == TextEditor::Snippet::Cpp)
        return true;
    return false;
}

void CppSnippetEditorDecorator::apply(TextEditor::SnippetEditor *editor) const
{
    CppHighlighter *highlighter = new CppHighlighter;
    const TextEditor::FontSettings &fs = TextEditor::TextEditorSettings::instance()->fontSettings();
    const QVector<QTextCharFormat> &formats =
        fs.toTextCharFormats(CPPEditor::highlighterFormatCategories());
    highlighter->setFormats(formats.constBegin(), formats.constEnd());
    editor->setSyntaxHighlighter(highlighter);
    editor->setIndenter(new CppQtStyleIndenter);
    editor->setAutoCompleter(new CppAutoCompleter);
}
