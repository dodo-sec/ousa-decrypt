```
  ___  _   _ ____    _      ____  _____ ____ ______   ______ _____ 
 / _ \| | | / ___|  / \    |  _ \| ____/ ___|  _ \ \ / /  _ \_   _|
| | | | | | \___ \ / _ \   | | | |  _|| |   | |_) \ V /| |_) || |  
| |_| | |_| |___) / ___ \  | |_| | |__| |___|  _ < | | |  __/ | |  
 \___/ \___/|____/_/   \_\ |____/|_____\____|_| \_\|_| |_|    |_|  
```

created by [dodo_sec](https://twitter.com/dodo_sec)

# ousa-decrypt
This is a simple program that implements the decryption routine for zip payloads used by the Ousaban/Javali malware family.

Please keep in mind this is meant to decrypt the zip archive only - **it does not decrypt content from the malware itself.**

Usage is simple: 
`ousa-decrypt [encrypted file] [output file]`

The seed 0x161a has been used by the Javali downloader DLLs for months now. I find it unlikely that will ever be changed - if it becomes a problem I can add a third argument to main for inputting a magic value instead of using a hardcoded one.
