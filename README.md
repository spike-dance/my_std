# My std

All the function, type and macro that I use in most of my C project.

## Build

To build tou just have execute build in sudo mode (only on linux for now):

```
sudo ./build
```

## Notes

Here are my write standard :

### Variable

|global variable|const  |pointeur/vector/function pointeur |struct/union |variable name  |
|:--------------|-------|:---------------------------------|:------------|:--------------|
|g              |c      |p/v/pfn                           |s/n          |_variableName  |

### Type

#### Unsigned
u\[bite count\]
#### Signed
i\[bite count\]

#### File
fd for linux file descriptor
iof for stdio stream

#### struct/union/enum
S/N/E + _ + typeName

#### Function pointeur
PFN_ + function name or a description of the type of function to point

### Preprocessor

All in capitale letter.

### Function

All function just start with fn_

### goto

All goto are in capitale letter and start with GO_ and if it's to quit a function GO_END_
