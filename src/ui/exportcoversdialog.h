/* This file is part of Clementine.
   Copyright 2010, David Sansome <me@davidsansome.com>

   Clementine is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Clementine is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Clementine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef EXPORTCOVERSDIALOG_H
#define EXPORTCOVERSDIALOG_H

#include <QDialog>

class Ui_ExportCoversDialog;

// Controller for the "Export covers" dialog.
class ExportCoversDialog : public QDialog {
  Q_OBJECT

 public:
  ExportCoversDialog(QWidget* parent = 0);
  ~ExportCoversDialog();

  enum OverwriteMode {
    OverwriteMode_None = 0,
    OverwriteMode_All = 1,
    OverwriteMode_Smaller = 2
  };

  struct DialogResult {
    bool cancelled_;

    QString fileName_;
    OverwriteMode overwrite_;
    bool forceSize_;
    int width_;
    int height_;

    bool IsSizeForced() const {
      return forceSize_ && width_ > 0 && height_ > 0;
    }

    bool RequiresCoverProcessing() const {
      return IsSizeForced() || overwrite_ == OverwriteMode_Smaller;
    }
  };

  DialogResult Exec();

 private slots:
  void ForceSizeToggled(int state);

 private:
  Ui_ExportCoversDialog* ui_;

  static const char* kSettingsGroup;
};

#endif // EXPORTCOVERSDIALOG_H
