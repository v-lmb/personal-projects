# Notes sur YARA

## Yet Another Ridiculous Acronym

---

## Les Bases de YARA
### Structure d'une règle YARA
Se compose de 3 parties principales :
```yara
rule NomDeLaRegle
{
    meta:
        // Métadonnées (informations sur la règle)
    
    strings:
        // Les motifs à rechercher
    
    condition:
        // Les conditions pour déclencher la règle
}
```


### 1.1 Les Métadonnées (meta)
Les métadonnées sont optionnelles mais recommandées. Elles documentent la règle :
```yara
meta:
    description = "Détecte un fichier suspect"
    author = "Ton nom"
    date = "2026-01-16"
    version = "1.0"
```


### 1.2 Les Strings (chaînes de caractères)
C'est ici que l'on définis ce que l'on cherche. 
Il existe plusieurs types :

* a) Chaînes de texte simples :
```yara
    $texte1 = "mot à chercher"
    $texte2 = "autre motif"
```


* b) Chaînes hexadécimales :
```yara
    $hex1 = { 4D 5A 90 00 }  // Signature d'un fichier PE Windows
```


* c) Expressions régulières :
```yara
    $regex1 = /[a-z]{5,10}@gmail\.com/  // Adresse email
```

### Modificateurs importants :

```nocase``` : insensible à la casse
```wide``` : pour les chaînes Unicode (Windows)
```ascii``` : pour les chaînes ASCII

```yara
    $s1 = "malware" nocase ascii wide
```


### 1.3 Les Conditions
La condition détermine quand la règle se déclenche :
```yara
    $texte1                    // Si $texte1 est présent
    all of them                // Si toutes les strings sont présentes
    any of them                // Si au moins une string est présente
    2 of them                  // Si au moins 2 strings sont présentes
    $texte1 and $texte2        // Si les deux sont présents
    $texte1 or $texte2         // Si l'un ou l'autre est présent
```


* Conditions avancées :
```yara
    filesize < 1MB             // Taille du fichier
    uint16(0) == 0x5A4D        // Les 2 premiers octets = "MZ"
    #texte1 > 5                // $texte1 apparaît plus de 5 fois
```

---


### Concepts Avancés pour Projet

## 2.1 Opérateurs utiles
```yara
and, or, not               // Opérateurs logiques
<, >, <=, >=, ==, !=      // Comparaisons
contains                   // Contient
matches                    // Correspond à une regex
```


## 2.2 Fonctions importantes
```yara
filesize                   // Taille du fichier
uint8(offset)             // Lit 1 octet à une position
uint16(offset)            // Lit 2 octets
uint32(offset)            // Lit 4 octets
```

