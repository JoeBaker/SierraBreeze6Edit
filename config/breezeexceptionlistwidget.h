#ifndef breezeexceptionlistwidget_h
#define breezeexceptionlistwidget_h
//////////////////////////////////////////////////////////////////////////////
// breezeexceptionlistwidget.h
// -------------------
//
// Copyright (c) 2009 Hugo Pereira Da Costa <hugo.pereira@free.fr>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//////////////////////////////////////////////////////////////////////////////

#include "breezeexceptionmodel.h"
#include "ui_breezeexceptionlistwidget.h"

//* QDialog used to commit selected files
namespace SierraBreeze
{

    class ExceptionListWidget : public QWidget
    {

        //* Qt meta object
        Q_OBJECT

      public:
        //* constructor
        explicit ExceptionListWidget(QWidget * = 0);

        //* set exceptions
        void setExceptions(const InternalSettingsList &);

        //* get exceptions
        InternalSettingsList exceptions(void);

        //* true if changed
        virtual bool isChanged(void) const
        {
            return m_changed;
        }

      Q_SIGNALS:

        //* emitted when changed
        void changed(bool);

      protected:
        //* model
        const ExceptionModel &model() const
        {
            return m_model;
        }

        //* model
        ExceptionModel &model()
        {
            return m_model;
        }

      protected Q_SLOTS:

        //* update button states
        virtual void updateButtons(void);

        //* add
        virtual void add(void);

        //* edit
        virtual void edit(void);

        //* remove
        virtual void remove(void);

        //* toggle
        virtual void toggle(const QModelIndex &);

        //* move up
        virtual void up(void);

        //* move down
        virtual void down(void);

      protected:
        //* resize columns
        void resizeColumns(void) const;

        //* check exception
        bool checkException(InternalSettingsPtr);

        //* set changed state
        virtual void setChanged(bool value)
        {
            m_changed = value;
            emit changed(value);
        }

      private:
        //* model
        ExceptionModel m_model;

        //* ui
        // Ui_BreezeExceptionListWidget m_ui;
        Ui_SierraBreezeExceptionListWidget m_ui;

        //* changed state
        bool m_changed = false;
    };

} // namespace SierraBreeze

#endif
