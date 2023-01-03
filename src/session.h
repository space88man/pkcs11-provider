/* Copyright (C) 2022 Simo Sorce <simo@redhat.com>
   SPDX-License-Identifier: Apache-2.0 */

#ifndef _SESSION_H
#define _SESSION_H

/* Slots */
CK_RV p11prov_init_slots(P11PROV_CTX *ctx, P11PROV_SLOTS_CTX **slots);
void p11prov_free_slots(P11PROV_SLOTS_CTX *slots);
CK_RV p11prov_take_slots(P11PROV_CTX *ctx, P11PROV_SLOTS_CTX **slots);
void p11prov_return_slots(P11PROV_SLOTS_CTX *slots);
P11PROV_SLOT *p11prov_fetch_slot(P11PROV_SLOTS_CTX *sctx, int *idx);
int p11prov_slot_get_mechanisms(P11PROV_SLOT *slot, CK_MECHANISM_TYPE **mechs);

/* Sessions */
CK_SESSION_HANDLE p11prov_session_handle(P11PROV_SESSION *session);
CK_SLOT_ID p11prov_session_slotid(P11PROV_SESSION *session);
CK_RV p11prov_get_session(P11PROV_CTX *provctx, CK_SLOT_ID *slotid,
                          CK_SLOT_ID *next_slotid, P11PROV_URI *uri,
                          CK_MECHANISM_TYPE mechtype,
                          OSSL_PASSPHRASE_CALLBACK *pw_cb, void *pw_cbarg,
                          bool reqlogin, bool rw, P11PROV_SESSION **session);
CK_RV p11prov_take_login_session(P11PROV_CTX *provctx, CK_SLOT_ID slotid,
                                 P11PROV_SESSION **_session);
void p11prov_return_session(P11PROV_SESSION *session);

#endif /* _SESSION_H */