/*
* This file is part of the Shiboken Python Bindings Generator project.
*
* Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
*
* Contact: PySide team <contact@pyside.org>
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation. Please
* review the following information to ensure the GNU Lesser General
* Public License version 2.1 requirements will be met:
* http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
*
* As a special exception to the GNU Lesser General Public License
* version 2.1, the object code form of a "work that uses the Library"
* may incorporate material from a header file that is part of the
* Library.  You may distribute such object code under terms of your
* choice, provided that the incorporated material (i) does not exceed
* more than 5% of the total size of the Library; and (ii) is limited to
* numerical parameters, data structure layouts, accessors, macros,
* inline functions and templates.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
* 02110-1301 USA
*/

#ifndef SIGNALMANAGER_H
#define SIGNALMANAGER_H

#include "pysidemacros.h"
#include <Python.h>
#include <Qt>
#include <QStringList>

class QObject;

namespace PySide
{

QStringList getArgsFromSignature(const char* signature);

class PYSIDE_API SignalManager
{
public:
    static SignalManager& instance();
    bool connect(QObject* source, const char* signal, PyObject* callback, Qt::ConnectionType type = Qt::AutoConnection);
    bool connect(QObject* source, const char* signal, QObject* receiver, const char* slot, Qt::ConnectionType type = Qt::AutoConnection);
    bool emitSignal(QObject* source, const char* signal, PyObject* args);
    void removeProxySlot(const QObject* signalSource);
    const QMetaObject* getMetaObject(const QObject* object) const;
private:
    struct SignalManagerPrivate;
    SignalManagerPrivate* m_d;
    SignalManager();
    ~SignalManager();

    // disable copy
    SignalManager(const SignalManager&);
    SignalManager operator=(const SignalManager&);
};

}
#endif