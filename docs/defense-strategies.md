# 🛡️ How to Defend Against Bootkits

## Detection Methods
1. **Secure Boot**: UEFI Secure Boot prevents unauthorized bootloaders.
2. **MBR Monitoring**: Tools like `mbrscan` can detect MBR modifications.
3. **Anti-Virus with Boot-Time Scanning**: Some AVs scan MBR during boot.

## Prevention
- Enable **Secure Boot** and **TPM**.
- Use **BitLocker** with TPM.
- Regularly backup your MBR.

## Response
- If infected, boot from a trusted USB and restore MBR.
- Use `bootrec /fixmbr` from Windows Recovery Environment.
